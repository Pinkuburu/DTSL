
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","跃马桥");
  set ("long", @LONG
面前宽达十多丈的永安大渠横断南北，在前方流过。一座宏伟的大
石桥，雄据水渠之上，桥下舟楫往来，桥上车马不绝。桥身以雕凿精致
的石块筑成像天虹般的大拱，跨距达十多丈，两边行人造夹着的军马道
可容四车并行，在大拱的两肩又各筑上两小拱，既利于排水，又可减轻
大拱的承担，巧妙的配合，令桥体轻巧美观，坡道缓和，造型出色。 
LONG);

  set("exits", ([ 
  "westdown":__DIR__"xishidongjie4",
  "eastdown":__DIR__"xishidongkou2",
        ]));
  set("objects",([
	  __DIR__"npc/xiaojie":1,
	  __DIR__"npc/youke":1,
	  __DIR__"npc/bing":1,
	  ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

