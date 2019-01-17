
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西湖湖畔");
  set ("long", @LONG
杭州西湖山青水秀，碧波涟漪，湖光山色，相映成趣，泛舟湖上犹
如镜中行，漫步湖堤则如画中游。西湖之美令人陶醉。自古以来，人们
常以艳、娇、媚、秀、柔、嫩来形容她。
LONG);

  set("exits", ([ 
  "south":__DIR__"hupao",
  "west":__DIR__"baiti",
        ]));
 
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

