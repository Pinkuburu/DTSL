
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","天街");
  set ("long", @LONG
这是一条汉白玉石砌成的平坦大道，宽十丈，北起横贯广场南至朱
雀门，是皇城内最大的一条街，所以人人都称为“天街”。天街两旁林立
着一座座各式各样的建筑，朝廷的各大机构，各级直属官署就在这里。
LONG);

  set("exits", ([ 
 "north":__DIR__"hggc2",
 "south":__DIR__"tianjie3",
 "east":__DIR__"taimiao",
 "west":__DIR__"taichangsi",
        ]));
   set("outdoors","changan");
   set("valid_startroom", 1);
  setup();
 
}

