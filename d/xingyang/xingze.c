inherit ROOM;

void create()
{
	set("short", "荥泽");
	set("long", @LONG
荥阳与紧傍大运河的荥泽，一主一副，实际是二而为一。荣泽等若
荣阳的大码头，是船只转驳的地点，而荣阳则是南船北马的转运处，又
是洧水和大运河物资交汇处。	
LONG );

	set("exits", ([
               "southwest"      : __DIR__"qingshilu2",
               "east"      : __DIR__"qingshilu3",
               "southeast"      : __DIR__"guanlu2",
               "northwest"      : __DIR__"matou",
		
	]));

 	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



