
inherit ROOM;
void create()	
{
	set("short","村南小路");
	set("long", @LONG
这里是扬州玩家村的村南小路。由于目前这里的人口非常少，
所以这里也只是修建了一条小路。这里花草茂盛，风景秀丽，可以
说是武林人士隐居的绝好去出。这里的地势不是很高，四周的群山
挡住了外来的冷风，所以这里四季如春。
LONG);
    set("exits", ([
	        "south" : __DIR__"nandajie2",
	        "east":__DIR__"wlq_sap",
	        "west":__DIR__"strong_cougar",
	        "north":__DIR__"nandajie4",
	       
 	]));
 	
      setup();
      replace_program(ROOM);
	
}
