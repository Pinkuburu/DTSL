// /d/zhuojun/yizhan.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "驿站");
	set("long", @LONG
这是一个旧隋朝的驿站，现在因为战乱，所以此驿站已经被荒费，
只要你在此经过，掀的灰尘将呛得你直咳嗽，所以几乎没人经过此处。
LONG
	);
set("outdoors", "/d/zhuojun");
set("exits", ([
                "south"  :__DIR__"xidajie1",
	]));
       setup();
	replace_program(ROOM);
}	
