
inherit ROOM;

void create()
{
	set("short", "经房");
	set("long", @LONG
这里是一个经房。旁边有几个书架，上面零散地放了几本经书。地
上积满了灰尘，看来已经许久没有人来过了。
LONG
	);
        set("outdoors", "成都");

	set("exits", ([
		"east":"/d/chengdu/dadian",
	]));
	set("objects",([
	  __DIR__"npc/heshang":1,
	  ]));

	setup();
	replace_program(ROOM);
}

