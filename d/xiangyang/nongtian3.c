
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","农田");
  set ("long", @LONG
这里是一片一望无际的农田，这里的人多半以耕作为生。由于这里
地处江汉平原，地质肥沃，所以这里的人生活虽不富裕，但是生活的也
不象其他地方的穷人那样清苦。
LONG);

  set("exits", ([ 
 "west":__DIR__"nongtian",
        ]));
  set("objects",([
      __DIR__"npc/nongfu":1,
      ]));
 set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

