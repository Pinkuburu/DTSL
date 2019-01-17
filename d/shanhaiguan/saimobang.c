// /d/gaoli/saimobang
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "塞漠帮大门");
        set("long", @LONG
这里山海关的塞漠帮的大门，几个帮众站在大门前注视着来的行人，
大门的上方有一块匾，是燕王高开道的亲笔手书。可见燕王和塞漠帮的关
系何等密切。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
            	"west" : __DIR__"dongdajie",
                "east" : __DIR__"siheyuan",
	]));
set("objects", ([
		__DIR__"npc/zhong" : 2,
	]));
       setup();
	replace_program(ROOM);
}
