
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"青云宫"NOR);
	set("long", @LONG
这里就是「青云宫」了。这里是东溟派掌门东溟夫人住的地方。东
边的墙上挂着一副画，画得是中原扬州城的风光，看来画中的扬州城还
是非常繁华。西边的墙上挂着一柄长剑。屋子的正中放着一个大方桌，
桌子上有一副尚为写完的诗词。
LONG);
	set("exits", ([
		"north":__DIR__"dayuan",
		"enter":__DIR__"woshi",
	]));

        
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

void init()
{
	add_action("do_sao","sao");
}

int do_sao(string arg)
{
	object ob;
	ob=this_player();
	if(!ob->query_temp("popo_job2"))
		return notify_fail("你在这里忙什么呢?\n");
	if((int)ob->query("sen",1)<8)
		return notify_fail("你太累了，歇歇吧!\n");
	if(ob->is_busy())
		return notify_fail("你正忙着呢?\n");
	if(!arg||arg!="宫") return notify_fail("你想做什么?\n");
	else
	{ 
	
			ob->add_temp("count",1);
		
		ob->receive_damage("sen",random(8));
		ob->start_busy(1);
		message_vision("$N认真的扫起青云宫来.\n",ob);
		  if((int)ob->query_temp("count",1)>10+random(3))
		  { ob->delete_temp("popo_job");
		    ob->delete_temp("popo_job2");
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
	case 0:message_vision("$N放下了手中的扫帚，觉得这里比刚才干净多了。\n",ob);break;
	case 1:message_vision("$N擦了擦汗，觉得自己又为东溟派出了一份力。\n",ob);break;
	case 2:message_vision("$N放下了手中的扫帚，觉得这里比刚才干净多了。\n",ob);break;
    }
	remove_call_out("return_job");
}                              