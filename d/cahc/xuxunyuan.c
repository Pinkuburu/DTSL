
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","续绚小院");
  set ("long", @LONG
这里是掖庭宫内的一个小园，适逢茶花盛开的季节，园中的茶花争
奇斗艳，竞相开放。园中有一个小池，池里游鱼晶莹剔透，池中央一座
假山上一条涓涓细流注入池中，好一幅山水田园图。
LONG);

  set("exits", ([ 
 "east":__DIR__"chengqingmen",
         ]));
  set("valid_startroom", 1);
  setup();
 
}

