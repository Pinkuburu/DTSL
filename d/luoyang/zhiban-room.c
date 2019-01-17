
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"休息室"NOR);
  set ("long", @LONG
这里是皇宫卫兵休息的地方。这里非常宽敞，一共是四间屋子连在
了一起，共摆放了大大小小十几张床。靠窗子的地方来放了几张桌子、
椅子，有几个护卫正在那里喝茶、聊天。
LONG);

  set("exits", ([ 
  "west":__DIR__"qingshilu3",
         ]));
   set("objects",([
	   __DIR__"npc/guanbing":2,
	   __DIR__"obj/changjian":2,
	   ]));
   set("sleep_room",1);
  
  set("valid_startroom", 1);
  setup();
 
}

