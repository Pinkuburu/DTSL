// /d/taiyuan/road7.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这里是一条土路。这里风沙很大，你一不小心就迷了眼睛。西边有
一座雄关，应该就是天下闻名的嘉峪关。
LONG );
	set("exits", ([
		"west"  : __DIR__"jiayuguan",
 		"east"  : __DIR__"road9",
        
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



