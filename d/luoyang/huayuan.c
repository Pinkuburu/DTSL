
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"花园"NOR);
  set ("long", @LONG
这里是曼清院的花园了。洛阳第一名妓尚秀芳经常在这里表演。每
天来听她弹曲子的人是络绎不绝。但并不是每个人都能入尚姑娘眼的。
LONG);

  set("exits", ([ 
	  "out":__DIR__"manqingyuan",
	  "west":__DIR__"xilou",
          "north":__DIR__"beilou",
          "south":__DIR__"nanlou",
  ]));
   set("objects",([
	   __DIR__"npc/shangxiu-fang":1,
	   ]));
   set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}
