
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路。这里的行人已经很少了。这里几乎没有什么人，
一片荒凉萧瑟的气氛。四周杂草丛生，只有几只野兔不时从你的脚前跑
过。
LONG);

  set("exits",([
	  "northwest":__DIR__"xiaolu2",
	  "southeast":"/d/xiangyang/dalu1",
	  
	  ]));
  set("outdoors","yinkui");
  set("valid_startroom", 1);
  setup();
 
}

