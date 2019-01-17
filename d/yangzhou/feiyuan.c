
#include <ansi.h>
#include <job_money.h>
inherit ROOM;


void create ()
{
  set ("short","废园");
  set ("long", @LONG
这里是一个废弃的园子，看来已经好久没人来这里了。这里杂草丛
生，给人一种阴森的感觉。据说这里经常闹鬼，普通百姓几乎不敢来这
里，这里也成了武林人士逃避仇家的好处所了。
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie3",
       ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_zuan","zuan");
  
}

int do_zuan()
{
  object ob;
  
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_csj_action1"))
  return 0;
  
  message_vision("$N悄悄撬开地上一个方砖，钻了进去！\n",ob);
  ob->move("/d/quest/csj/migong1");
  
  return 1;
}