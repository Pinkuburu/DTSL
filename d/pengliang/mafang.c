inherit ROOM;


void create()
{
	set("short", "马厩");
	set("long", @LONG
这里是马厩，少帅军想要建立一支强大的骑兵，战马是主要的，这
里就是养战马的地方，圈里的战马各个膘肥体壮，被刷洗的干干净净。
LONG
	);
        set("outdoors", "pengliang");


	set("exits", ([
		"south" : __DIR__"jiedao4",
	]));
	
	set("objects",([
	 __DIR__"npc/mafu":1,
	 ]));
	 
	setup();
	replace_program(ROOM);
}

