
#include <ansi.h>
inherit ROOM;
int do_search();

void create ()
{
  set ("short","丹房");
  set ("long", @LONG
这里是阴癸派的丹房。阴癸派作为江湖第一大邪派，少不了要使用
写独门毒药等阴毒的东西。这里就是阴癸派炼制毒药的地方。只见这里
香气缭绕，透漏出一股诡异的气氛。
LONG);
  set("exits",([
	  "south":__DIR__"qingshilu5",
	  ]));

 
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_search","search");
}

int do_search()
{
   object ob,obj;
   
   ob=this_player();
   
   if(ob->is_busy())
   return notify_fail("你正忙着呢！\n");
   message_vision("$N四下搜索起来。\n",ob);
   
   obj=new(__DIR__"obj/yao");
   obj->move(ob);
   tell_object(ob,"你弄到一点东西！\n");
   ob->start_busy(1+random(2));
   return 1;
}