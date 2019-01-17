
#include <ansi.h>
inherit ROOM;

int do_tiao();
void create ()
{
  set ("short",WHT"瀑布中"NOR);
  set ("long", @LONG
这里是瀑布的下面，从上而下的猛烈的水流砸在你的身上，溅起阵
阵水花。水流很大，遮住了你的视线，只能看见眼前一片白光，水落的
轰鸣声音震的你耳朵有些发麻。
LONG);

  set("exits", ([ 
 "out":__DIR__"pubu",
     ]));
  set("add_force",1);
   set("valid_startroom", 1);
   set("outdoors","huashan");
   set("no_select",1);
  setup();
 
}

void init()
{
	object *ob,here;int i;
	add_action("do_tiao","tiao");
	here=load_object(__DIR__"shui");
	ob=all_inventory(here);

	for(i=0;i<sizeof(ob);i++)
	{
		if(objectp(ob[i])&&ob[i]->query_skill("force",1)<100&&
			!ob[i]->query_temp("add_force")){
			ob[i]->set_temp("add_force",1);
			call_out("add_force",1,ob[i]);
		}
	}
	return;
}

void add_force(object ob)
{
	object here;
	if(!ob) return;
	here=environment(ob);
	if(!here->query("add_force")){
	 ob->delete_temp("add_force");
	 return;
	}
	if(ob->query_skill("force",1)>=101)
	return;
	if(ob->is_busy())
	return;
	tell_object(ob,"\n水流猛地朝你的头上冲了下来!\n");
	if(ob->query("sen")<ob->query_skill("force",1)/3)
	{
		message_vision("$N觉得非常疲劳，已经支持不住了！\n",ob);
		ob->unconcious();
		ob->move(__DIR__"pubu");
		return ;
	}
	ob->receive_damage("sen",ob->query_skill("force",1)/3?ob->query_skill("force",1)/3:1);
	ob->improve_skill("force",ob->query_skill("force",1)/3+ob->query_int()/2);
	tell_object(ob,"你运气全身，咬牙扛了过来！\n");
	call_out("add_force",3+random(2),ob);
	return;
}

int do_tiao()
{
	object ob;
	ob=this_player();
	message_vision("$N朝旁边的潭水跳了过去！\n",ob);
	ob->move(__DIR__"tan");
    return 1;
}
