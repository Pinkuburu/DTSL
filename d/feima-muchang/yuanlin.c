
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"园林"NOR);
  set ("long", @LONG
这里是个小园林。这里的景色错落有至，假山怪石嶙峋，让人留恋
往返。更看出飞马场主的眼光独到之处。这里种了很多的鲜花，花的品
种繁多，个个色彩艳丽，美丽鲜艳。而且花的颜色搭配得当，一看起来
就让人赏心悦目.
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"qingshilu3",
	  "southwest":__DIR__"xiaolu3",
	  "east":__DIR__"yuedongmen",
	  "north":__DIR__"qingshilu4",
	  "southeast":__DIR__"qingshilu2",
         ]));
  set("objects",([
	  __DIR__"npc/liangzhi":1,
	  ]));
set("outdoors","feima");
  
  set("valid_startroom", 1);
  setup();
 
}

