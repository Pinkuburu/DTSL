
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南湖堤");
  set ("long", @LONG
这里是扬州城的南湖堤。南边传来一些喧哗声，打破了这里的宁静。
这里怪石嶙峋，参差起伏，另有一番风采。再往东南过了第二段堤就是
扬州的南大街了。
LONG);

  set("exits", ([ 
 "east":__DIR__"nanhudi2",
 "northwest":__DIR__"xihudi",
        ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

