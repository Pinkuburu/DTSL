// /d/taiyuan/road7.c
// Room in 太原
// modify by yang

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这里是一条进山的小路，感觉路越来越抖了。眼前的这座大山，以
其险峻闻名天下，人称“西岳华山”。
LONG );
	set("exits", ([
		"northwest"  : __DIR__"road8b",
 		"southeast":"/d/huashan/shanlu1",
		
	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



