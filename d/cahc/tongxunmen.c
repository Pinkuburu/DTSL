
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","通训门");
  set ("long", @LONG
通训门是皇宫内太极宫通往东宫的要门，宫内势力复杂，斗争严峻，
所以虽然同处皇宫，但是这里的守卫依然很森严，门呈长方形，以条石
为基，巨砖为墙，极为坚固。
LONG);

  set("exits", ([ 
 "eastup":__DIR__"chengendian",
 "west":__DIR__"dongyuchi",
        ]));
  set("objects",([
          "/d/cahc/npc/liaonan":1,
          ]));
  

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

