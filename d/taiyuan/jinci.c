// /d/taiyuan/jinci.c
// Room in 太原
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "晋祠");
	set("long", @LONG
这里是太原的晋祠，但是由于连年的战乱，这里已经破旧不堪，几
乎没有什么人来这里了。
LONG
	);
set("exits", ([
                "west" : __DIR__"beidajie1", 
	]));
 set("objects",([ __DIR__"npc/girl2":1,]));
       setup();
	replace_program(ROOM);
}	
