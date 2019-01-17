
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","凉亭");
  set ("long", @LONG
这里是一座凉亭，构造简单，供来往的游人休息用。这里风景秀丽，
山水如画，空气清新。远处的地上有很多漂亮的野花、蒲公英等植物。不
时有野兔从你的脚旁跳过。
LONG);

  set("exits", ([ 
 "east":__DIR__"shanlu2",
 "west":__DIR__"shanlu3",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

