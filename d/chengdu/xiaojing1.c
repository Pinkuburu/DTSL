
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
  
	  "northwest":__DIR__"ceyuan",
	  "southwest":__DIR__"xiaojing2",
      ]));
 set("outdoors","chengdu");
  set("valid_startroom", 1);
  setup();
 
}
