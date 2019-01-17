
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路，两旁种了很多鲜花，个个色彩鲜艳，妖艳无比，
一看就知道是毒花毒草。东边是阴癸派的厨房，不时从那里传来阵阵香
气。不时有弟子走来走去。
LONG);
  set("exits",([
	  "west":__DIR__"qingshilu2",
	  "east":__DIR__"chufang",
	  ]));

  set("outdoors","yinkui");

  set("valid_startroom", 1);
  setup();
 
}

