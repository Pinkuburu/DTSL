inherit ROOM;


void create()
{
	set("short", "城门");
	set("long", @LONG
这里是彭城的南城门，彭城毁于契丹马贼之手，少帅军占领彭梁以
后，开始重建彭城，这个城门就是新建的，虽然并不雄伟，但却很坚固，
城墙都是由青石垒成，灌以泥浆。
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"north" : __DIR__"jiedao4",
		"south":"/d/yangzhoubei/shanlu13",
	]));
         set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
	setup();
	replace_program(ROOM);
}

