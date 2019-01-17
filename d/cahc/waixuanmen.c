
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","外玄门");
  set ("long", @LONG
这里是皇城的北大门，门上提着四个金笔大字「外玄武门」。夕阳
照在黄瓦宫殿的琉璃瓦上，金壁辉煌，令人目为之炫。这里守卫深严，
等闲平常百姓根本不得接近。
LONG);

  set("exits", ([ 
 "north":"/d/changan/tydajie4",
 "south":__DIR__"xineiyuan",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":4,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

