
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","我意楼");
  set ("long", @LONG
这里就是兰斯洛和菀苑的书房，只见房中到处都是经典古籍
堆积如山，墙上挂满名人字画。屋中有一个红色的书桌，旁边几
把椅子。桌上有一张焦尾古琴，兰苑夫妇常在这里吟诗弹琴，好
不惬意。
LONG);

  set("exits", ([ 
 "west":__DIR__"xsl",
      ]));
 set("valid_startroom", 1);
  setup();
 
}

