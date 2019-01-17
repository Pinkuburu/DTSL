
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","玄武门");
  set ("long", @LONG
这里是皇宫的北大门玄武门，也是皇宫内最重要的大门，放眼望去，
但见金钉朱户，画栋雕梁，门顶尽覆铜瓦，镌镂龙凤飞镶之状，巍峨壮
丽，光耀溢目。禁宫卫士衣甲鲜明，来回巡视。
LONG);

  set("exits", ([ 
 "north":__DIR__"qingshilu2",
 "south":__DIR__"yuhuayuan",
        ]));
  set("objects",([
          "/d/cahc/npc/changhe":1,
          "/d/changan/npc/bing":4,
          ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

