
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧室");
  set ("long", @LONG
这里是独尊堡的堡主解晖的卧室了。床上的被褥叠得很整齐。旁边
的桌子上整齐地放着文房四宝。这里看来很整洁，似乎是刚刚打扫过。
LONG);

  set("exits", ([ 
  
	  "north":__DIR__"changlang1",
       ]));
  set("objects",([
	  __DIR__"npc/xiehui":1,
	  ]));
set("no_clean_up",1);
  set("valid_startroom", 1);
  setup();
 
}
