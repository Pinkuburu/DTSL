// /d/taiyuan/nroad3.c
// Room in 太原
// modify by yang

inherit ROOM;
void create()
{
	set("short", "大官道");
	set("long", @LONG
你走在一条尘土飞扬的大官道上。此处以人群稀少。北面就是大草
原了。
LONG
        );
set("outdoors", "/d/taiyuan");
set("valid_startroom", 1);
set("exits", ([
                "southup":__DIR__"changcheng9",
                "north":__DIR__"nanmen",

	]));
       setup();
	replace_program(ROOM);
}
