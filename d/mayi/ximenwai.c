// rich 99/04/05
inherit ROOM;
void create()
{
	set("short", "西门外");
	set("long", @LONG
你走出了马邑的西门，这里是一望无际的平原，黄色的土，绿色的
草，蓝蓝的天，天底下，草原上有一群群的牲畜，偶尔还有有一群野马
跑过。
LONG
	);
set("outdoors", "/d/mayi");
set("valid_startroom", 1);
set("exits", ([
                "east" : __DIR__"ximen",
                "west" : __DIR__"huangtu1",
	]));
       setup();
	replace_program(ROOM);
}
