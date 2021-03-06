
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"gangkou"
#define TO __DIR__"gangkou2"
int do_yell(string arg);
void create ()
{
  set ("short","港口");
  set ("long", @LONG
这里是东溟派北边唯一的港口。面前是一望无际的大海。阵阵波涛
拍打在岸边，发出轰鸣的声音。有几艘船停留在这里，看样子是准备出
海远行了。
LONG);

  set("exits", ([ 

  "south":__DIR__"haitan1",
         ]));
  set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
  set("valid_startroom", 1);
  set("outdoors","gangkou");
  setup();
 
}

void init()
{
	add_action("do_yell","yell");
}

int do_yell(string arg)
{
	object ship,here,me;int force;
	ship=find_object(SHIPDIR);
	ship=load_object(SHIPDIR);
	me=this_player();
	here=environment(me);
	force=me->query("force");
	if(!arg||(arg!="boat"&&arg!="船家")) return notify_fail("你要喊叫什么?\n");
	if(force<=500) message_vision("$N使足了力气喊道:船家～～～!\n",me);
	else if(force<=1000) message_vision("$N用力喊道:船家～～～!声音远远传了出去.\n",me);
	else if(force<=2000) message_vision("$N鼓足中气用力喊道:船家～～～!声音远远传了出去.\n",me);
	else message_vision("$N高声喊道:船家～～～!声音悠扬,经久不息.\n",me);
	
	if(me->query("family/family_name")=="东溟派"){
	   message_vision("\n船家朝$N做了个揖：原来是东溟派弟子，请随我乘这艘小船去海岛。\n",me);
	   message_vision("\n只见一艘小船驶了过来，$N纵身一跃，跳入了小船中！\n",me);
	   tell_object(me,"\n只见小船迅速的滑动，转眼已到了东溟派的海岛。\n");
	   me->move(TO);
	   message_vision("$N从小船中跳了下来。\n",me);
	   return 1;}
	
	if(ship->query("yell"))
		if(ship->query("exits/out")==FROM)
			return notify_fail("快上来吧,船马上就开了!\n");
	else return notify_fail("艄公喊道:等等啊～～～一会就来了～～～\n");
	ship->set("yell",1);
	ship->set("exits/out",FROM);
	here->set("exits/enter",SHIPDIR);
	tell_object(here,"艄公说道:客官,让您久等了,快请上船吧!\n");
	call_out("on_board",10,me,ship,here);
	return 1;
}

void on_board(object me,object ship,object here)
{
   tell_object(ship,"艄公喊道:各位客官坐好,开船了～～～\n");
   tell_object(here,"艄公喊道:各位客官坐好,开船了～～～\n");
	ship->delete("exits");
   here->delete("exits/enter");
   call_out("leave_ship",30,me,ship);
   remove_call_out("on_board");
}

void leave_ship(object me,object ship)
{
	object here;
	ship->set("exits/out",TO);
    here=load_object(TO);
	here->set("exits/enter",SHIPDIR);
	tell_object(ship,"艄公说道:客官,到岸了,下船吧!\n");
	call_out("no_ship",1,ship,here);
	remove_call_out("leave_ship");
}

void no_ship(object ship,object here)
{
   object *ob;int i;
   ob=all_inventory(ship);
   for(i=0;i<sizeof(ob);i++)
   {
	   if(living(ob[i]))
		   ob[i]->move(here);
	   else
	   {
		   tell_object(ship,"艄公一脚把"+ob[i]->name()+"踹下船!\n");
		   tell_object(here,"艄公一脚把"+ob[i]->name()+"踹下船!\n");
		   ob[i]->move(here);
	   }
   }
   ship->delete("exits");
   ship->delete("yell");
   here->delete("exits/enter");
   remove_call_out("no_ship");
}