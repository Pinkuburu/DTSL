
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","明德门");
  set ("long", @LONG
这里就是七大古都长安的南门，历史上如西周，西汉，隋朝等许多
的王朝都在此见都，所以当地的人口众多，经济也相当繁华。经过这里
的商人，游客络绎不绝，偶尔还能看见几个拿着兵器的侠客经过。城门
前站着几个士兵，在盘问检查经过的人们。
LONG);

  set("exits", ([ 
 "west":__DIR__"xiaolu9",
 "north":__DIR__"zqdajie1",
 "southeast":__DIR__"guanlu3",
 "east":__DIR__"xiaolu8",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  __DIR__"npc/wujiang":1,
	  ]));
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

