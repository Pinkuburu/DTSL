inherit ROOM;

void create()
{
	set("short", "青石路");
	set("long", @LONG
这是一条由青色条石铺成的大道，道面由四辆马车并行那样宽，这
条大道是用语连接荥阳和荥泽，荣泽等若荣阳的大码头，是船只转驳的
地点，而荣阳则是南船北马的转运处，又是洧水和大运河物资交汇处。
所以这条大道上的车马行人来往不断。
LONG );

	set("exits", ([
               "southeast"      : __DIR__"tulu1",
               "north"      : __DIR__"qingshilu2",
		
	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



