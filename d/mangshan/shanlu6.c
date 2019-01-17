
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山谷");
  set ("long", @LONG
这里是个山谷，四周群山环绕，景色秀丽。地上有很多漂亮的野花、
蒲公英等植物。不时有野兔从你的脚旁跳过。北面的山峰上有一座庙宇。
LONG);

  set("exits", ([ 

  "westup":__DIR__"shanlu5",
 "northeast":__DIR__"shanlu7",
 "south":__DIR__"caodi1",
 "northup":"/d/job/sjbjob/biyunfeng",
         ]));
  set("objects",([
	  __DIR__"npc/monkey":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

