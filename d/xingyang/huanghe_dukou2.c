
#include <ansi.h>
inherit ROOM;
#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huanghe_dukou2"
#define TO __DIR__"huanghe_dukou1"
#include "/std/shiproom.c"
void create ()
{
  set ("short","黄河渡口");
  set ("long", @LONG
这里是黄河的渡口。面前黄河滚滚，气势惊人。只有一叶扁舟载来
往的行人。
LONG);

  set("exits", ([ 
  "southwest":__DIR__"qingshilu4",
  "south":__DIR__"dadao1",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

