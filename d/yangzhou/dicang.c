
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","底舱");
  set ("long", @long
这里堆积着一些压仓物和一些陈年佳酿，不过没有船主的钥匙是无
法拿到那些锁在柜子里的美酒的。
long);

  set("exits", ([ 
 "up":__DIR__"chuancang5",
 ]));
 
  set("valid_startroom", 1);
  setup();
 
}

