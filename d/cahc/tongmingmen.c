
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","通明门");
  set ("long", @LONG
通明门是皇宫内太极宫通往掖庭宫的要门，宫内势力复杂，斗争严
峻，所以虽然同处皇宫，但是这里的守卫依然很森严，门呈长方形，以
条石为基，巨砖为墙，极为坚固。
LONG);

  set("exits", ([ 
 "westup":__DIR__"houdian",
 "east":__DIR__"xiyuchi",
        ]));
  set("objects",([
          "/d/cahc/npc/chengmo":1,
          ]));
  

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

