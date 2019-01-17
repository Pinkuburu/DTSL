
#include <ansi.h>
inherit ROOM;

int do_wa();
void create ()
{
  set ("short","山洞");
  set ("long", @LONG
这里山洞，里面静悄悄的，看来没有什么人。你轻轻地咳嗽了一声，
只听见回声在你耳边回荡。
LONG);

  set("exits", ([ 

   "west":__DIR__"shanlu3",
   
          ]));
 set("objects",([
     __DIR__"npc/she":2,
     ]));
//set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_wa","wa");
}

int do_wa()
{
  object ob;
  object cao;
  
  ob=this_player();
  if(ob->is_busy()||
     ob->is_fighting())
  return notify_fail("你正忙着呢！\n");
  if(query("no_dig"))
  return notify_fail("这里好象没有什么东西了。\n");
  if(ob->query("sen")<50)
  return notify_fail("你感到精神疲惫，好象该休息一下了。\n");
  message_vision("$N在地上挖了起来。\n",ob);
  ob->receive_damage("sen");
  if(random(20)>10){
  	cao=new("/d/quest/poison/obj/cao2");
  	cao->move(environment(ob));
  	message_vision("$N挖到了一棵"+cao->query("name")+"。\n",ob);
  	set("no_dig",1);
  	return 1;}
  ob->start_busy(2);
  return 1;
}