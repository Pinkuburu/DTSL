

inherit ROOM;

void create()
{
	set("short", "湖边路");
	set("long", @LONG
这是万岁湖南岸。南边就是成都著名的独尊堡了。有几名独尊堡在
这里走来走去，巡视着来往的行人。
LONG
	);
        set("outdoors", "成都");

	set("exits", ([
		"northeast":__DIR__"wansuihu",
		"southwest":__DIR__"duzunbao",
		
	]));

	setup();
	replace_program(ROOM);
}

