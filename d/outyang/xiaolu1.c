
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。北边是一片树林，南面就是淮河了。这里的行人
不是很多。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shulin2",
 "northeast":__DIR__"shulin4",
 "southeast":__DIR__"huaihebei",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

