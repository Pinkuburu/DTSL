
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北湖堤");
  set ("long", @LONG
这里是扬州城的北湖堤。平日里人潮汹涌，湖堤旁停靠着多艘花船，
几十名花船上的龟公在这里拉客，正应了那两句诗：十年一觉扬州梦，赢
得青楼薄幸名。
LONG);

	set("exits", ([ 
 		"west":__DIR__"guangchang",
 		"south":__DIR__"donghudi",
 		"southwest":__DIR__"matou",
        ]));
	set("objects",([
		__DIR__"npc/guigong":1,
	]));

    set("outdoors","yangzhou");
    set("no_fight",1);
	
	set("valid_startroom", 1);
	setup();
 
}
int valid_leave(object me,string dir)
{
	if(!me->query_temp("gived_money")&&dir=="southwest")
		if(objectp(present("xiao",environment(me))))
			return notify_fail("龟公拦住了你：客官，您还没给钱呢!\n");
		else return notify_fail("龟公说道：客官，怎么着，想硬闯啊？!\n");
		return ::valid_leave(me,dir);
		return 1;
}
