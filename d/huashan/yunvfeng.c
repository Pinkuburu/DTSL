
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","玉女峰");
  set ("long", @LONG
中峰居东、西、南三峰中央，是依附在东峰西侧的一座小峰，峰上
林上葱茏，环境清幽，奇花异草多不知名，游人穿行其中，香襟袖。峰
头有道舍名玉女祠，传说是春秋时秦穆公女弄玉的修身之地，因此峰又
被称为玉女峰。
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"shanlu6",
 "northdown":__DIR__"yanggongta",
       ]));
       /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
  set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
