
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","羊肠小径");
  set ("long", @LONG
这里是一个羊肠小径，曲曲折折。两边种了很多花草，花的品种不
是很多，种花五彩缤纷，色彩艳丽，让人赏心悦目。
LONG);

  set("exits", ([ 
  
	  "northeast":__DIR__"xiaojing1",
	  "southeast":__DIR__"xiaojing3",
      ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
