
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"花园"NOR);
  set ("long", @LONG
这里是个小花园。这里种了很多的鲜花，虽然花园不大，但是花的
品种繁多，个个色彩艳丽，美丽鲜艳。而且花的颜色搭配得当，一看起
来就让人赏心悦目.
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"caodi1",
	  "southeast":__DIR__"xiaolu2",
         ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

