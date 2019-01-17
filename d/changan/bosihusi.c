
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","波斯胡寺");
  set ("long", @LONG
这里是一座巍峨宏伟的波斯胡寺，很多从波斯来的客商都要到这里
来朝拜，胡寺形状独特，蘑菇状的大圆塔尖顶耸峙在附近民房之上，远
处的人一目了然。
LONG);

  set("exits", ([ 
 "east":__DIR__"zqdajie4",
       ]));
  set("objects",([
         __DIR__"npc/shangren2":2,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

