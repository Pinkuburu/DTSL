
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","药店");
  set ("long", @LONG
这里是一家药店。由于战乱连年，所以这里的生意很好。这里的药
物种类齐全，在襄阳城享有很高的声誉。老板最近招收学徒，所以药师
一时成了襄阳的热门职业。几个学生正在学习药店老板炼制药物的方法。
LONG);

  set("exits", ([ 
 "north":__DIR__"dongdajie3",
 "enter":__DIR__"yaoshigh",
        ]));
 set("objects",([
	 __DIR__"npc/shangguan":1,
	 ]));
 set("valid_startroom", 1);
  setup();
 
}
/*
int valid_leave(object me,string dir)
{
        if(me->query("vocation")!="药师" && dir=="enter")
                return notify_fail("你不是药师，不能进入药师工会!\n");
                return ::valid_leave(me,dir);
                return 1;
}
*/
