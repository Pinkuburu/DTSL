#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "港口");
        set("long", @LONG
这里是高丽的港口，这里非常热闹，停泊着各种船只，有货
船，商船等等。很多旅客从这里进出港口，有从中原来的，也有
从其它地方来的。许多小贩在这里叫卖。
LONG
);
        set("exits",([
	"west" : "/d/gaoli/gangkou",
        ]));
        set("objects",([
          __DIR__"han":1,
          ]));
set("outdoors","out");
        setup();
//        replace_program(ROOM);
}
