
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","摆尾峰");
  set ("long", @LONG
这里就是卧龙岭上的摆尾峰，西边是游龙峰。这里地势起伏不定，
但是相比望天角要平坦得多。东边是一片茂密的松树林。南北两边都是
陡峭的悬崖峭壁。一阵风吹来，风雪扑面而来。
LONG);

  set("exits", ([ 
 "westup":__DIR__"wolong6",
 "east":__DIR__"shulin",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

