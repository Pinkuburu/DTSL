
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。这里的景色十分秀丽。不时有游人和你擦肩而过。
鲜花绿草若隐若现，随着山谷里吹来的阵阵清风，传来哗哗的松涛声和一
些淡淡的花香。这条路通向峨眉山。
LONG);

  set("exits", ([ 
 "westup":__DIR__"shanjiao",
 "eastdown":__DIR__"shanlu5",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

