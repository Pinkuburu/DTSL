
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","碧霞祠");
  set ("long", @LONG
这里是泰山的碧霞祠。祠祠院设有东西两殿，分别称为东西宝库，
储存着进香客的捐施，两殿的屋瓦都是由铁铸成。从四方八面来泰山上
香的男女，都是先到碧霞祠，然后才到其他的庙宇。他的庙宇。
LONG);

  set("exits", ([ 

   "westup":__DIR__"nantianmen",
   "eastup":__DIR__"yuhuangding",
   "eastdown":__DIR__"wusongting",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

