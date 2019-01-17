
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"兵器库"NOR);
	set("long", @LONG
这里是东溟派的兵器库。地上散乱地放着很多兵器，如刀、剑等。
旁边还有一个工人在打磨着兵器。
LONG);
	set("exits", ([
		"east":__DIR__"tingyuan",		
	]));
    set("objects",([
		__DIR__"obj/changjian":1,
                __DIR__"obj/hammer":4,
		__DIR__"obj/blade":1,
		__DIR__"obj/whip":3,
		]));
        
       set("valid_startroom", 1);   
	setup();
       
       
}

void init()
{
	add_action("do_mo","mo");
}

int do_mo(string arg)
{
	object ob;
	ob=this_player();
	if(!ob->query_temp("popo_job3"))
		return notify_fail("你在这里忙什么呢?\n");
	if((int)ob->query("sen",1)<8)
		return notify_fail("你太累了，歇歇吧!\n");
	if(ob->is_busy())
		return notify_fail("你正忙着呢?\n");
	if(!arg||arg!="兵器") return notify_fail("你想做什么?\n");
	else
	{ 
	
			ob->add_temp("count",1);
		
		ob->receive_damage("sen",random(8));
		ob->start_busy(1);
		message_vision("$N认真的来磨起兵器来.\n",ob);
		  if((int)ob->query_temp("count",1)>10+random(3))
		  { ob->delete_temp("popo_job");
		    ob->delete_temp("popo_job3");
			ob->set_temp("popo_ok",1);
		    ob->delete_temp("count");
			printf("你可以回去复命了!\n");
			return 1;
		  }
		  call_out("return_job",1,ob);
		  return 1;
	}
	
}

void return_job(object ob)
{
	switch(random(3))
	{
	case 0:message_vision("$N在磨兵器的过程中,不禁想立刻成为一个啸傲江湖的大侠。\n",ob);break;
	case 1:message_vision("$N看了看手中的兵器，不禁想到武林中要有多少人要丧生于争斗之中了。\n",ob);break;
	case 2:message_vision("$N擦擦头上的汗，觉得手中的兵器磨得好多了。\n",ob);break;
	}

	remove_call_out("return_job");
}

