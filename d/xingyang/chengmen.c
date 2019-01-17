inherit ROOM;

void create()
{
	set("short", "内城城门");
	set("long", @LONG
此间是荥阳城内城的城门，荥阳为河南重镇。内城城墙由石块和土
垒成，高丈五，厚达丈余。城下三两个盔甲鲜明的军士，向南就是荥阳
的内城了。
LONG );

	set("exits", ([
                          "north"      : __DIR__"center",
                         "south"      : __DIR__"ncenter",
                         "east":"/d/clone/room/cityroom/xingyang",
		
	]));
    set("objects",([
     __DIR__"npc/bing":2,
     "/d/job/questjob/npc/zhairang":1,
     
     ]));

 	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



