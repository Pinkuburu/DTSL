
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huanghenan"
#define TO __DIR__"huanghebei"
#include "/std/shiproom.c"

void create ()
{
  set ("short","黄河南岸");
  set ("long", @LONG
这里是黄河的南岸。面前是滚滚的黄河，你不禁生出一股豪气。你
可以在叫船家(yell boat)，就可以乘舟到黄河北岸了。
LONG);

  set("exits", ([ 

  "southwest":__DIR__"shanlu5",
"west":"/d/pengliang/huanghe3"
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}

