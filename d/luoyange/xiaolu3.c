
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里已经是堰师的境地了。这里来来往往很多武林人士，看来都是
去飞马牧场的。这里地势一片空阔，四处望去一片平坦。不是有鸟儿从
你的头上飞过。
LONG);

  set("exits", ([ 
  "southwest":__DIR__"xiaolu2",
  "northwest":__DIR__"shanlu1",
  "east":"/d/yangzhoubei/xiaolu4",
        ]));
 set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

