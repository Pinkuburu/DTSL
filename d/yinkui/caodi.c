
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","草地");
  set ("long", @LONG
这里是一片草地。这里非常安静，显出安静享和的气氛。两旁种了
很多鲜花，个个色彩鲜艳，妖艳无比，一看就知道是毒花毒草。再往北
边走，就是阴癸派长老边不付的卧室了。
LONG);
  set("exits",([
	  "southeast":__DIR__"houdian",
	  "north":__DIR__"xiaojing1",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

