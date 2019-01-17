
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条上山的小路。这里的景色十分秀丽。西面有一座凉亭。
北面是一片树林。鲜花绿草若隐若现，随着山谷里吹来的阵阵清风，传
来哗哗的松涛声和一些淡淡的花香。
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"shanlu1",
 "west":__DIR__"liangting",
 "north":__DIR__"shulin",
       ]));
   set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

