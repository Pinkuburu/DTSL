
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","书铺");
  set ("long", @LONG
这里是一家书铺，这里有很多书籍，有文学的，天文的，武功方面
的等等。虽然是一家书铺，但也免不了被江湖帮会所欺压，老板经常要
从微薄的收入中取出很大一部分做为保护费。现在书铺冷冷清清，老板
正看着书架上的一摞摞书发呆。
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie2",
        ]));
 set("objects",([
	 __DIR__"npc/kong":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}

