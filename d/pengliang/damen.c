inherit ROOM;

void create()
{
	set("short", "少帅府大门");
	set("long", @LONG
这是少帅府的大门，门板不知是以什么材料制成，看上去黝黑一片，
似乎极为沉重，上面有两个擦得晶亮的铜环；在大门的正前面有个立着一
个高大的旗杆，旗上书「少帅军」三个大字。门前东西两边各肃立着两个
腰配大刀的少帅军官兵。
LONG );
        set("outdoors", "pengliang");

	set("exits", ([
		"west" : __DIR__"nandajie",
                "north" : __DIR__"yuanzi",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
        "/d/clone/npc/chvocation_npc":1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" &&
                objectp(present("song bing", environment(me))))
           return notify_fail("官兵向你喝道：什么人胆敢擅闯少帅府！\n");

        return ::valid_leave(me, dir);
}
