
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里是一片一望无垠林海，每棵树木都有十来丈高，周围阡陌交错，
几十丈高的大树簇在一块，密实的枝叶象一蓬蓬巨伞般伸向天空，把阳
光遮得丝毫也无。你侧耳倾听，似乎有溪水流动的声音。
LONG);

  set("exits", ([ 

  "northwest":__DIR__"shulin7",
  "southeast":__DIR__"shulin4",
  "south":__DIR__"shulin5",
    ]));
  
set("outdoors","baling");
  
  set("valid_startroom", 1);
  setup();
 
}

