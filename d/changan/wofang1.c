
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧房");
  set ("long", @LONG
这里就是东来客栈的卧房了，旁边的卧房内传出阵阵鼾声，你也不觉
困了起来，看来该休息一下了。
LONG);

  set("exits", ([ 
 "down":__DIR__"donglaikezhan",
 
        ]));
  set("sleep_room",1); 
  set("valid_startroom", 1);
  setup();
 
}
int valid_leave(object me,string dir)
{
	if(dir=="down")
		me->delete_temp("gived_money");
	return ::valid_leave(me,dir);
}
