
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangbei"
#define TO __DIR__"matou"
#include "/std/shiproom.c";
void create ()
{
  set ("short","长江北岸");
  set ("long", @LONG
这里是长江的北岸。过了长江，就是江西的境地了。这里行人很多，
多是乘传的旅客和买卖东西的商贩。叫卖的声音不绝于耳，远处又有几艘
大船驶了过来。过了长江，就可以到九江了。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"xiaolu1",
  "northwest":__DIR__"caocong1",
  "north":"/d/hefei/caodi2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

