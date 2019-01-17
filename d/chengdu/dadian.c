
inherit ROOM;

void create()
{
	set("short", "大殿");
	set("long", @LONG
这是寺庙的大殿。这里冷冷清清的，没什么人来上香。佛像也有些
破旧了，香案上除了几住香就再没有其他东西了。地上放着一个破旧的
蒲团和一个木鱼，旁边有一个僧人正在那里念经。里念经。
LONG);
	set("exits", ([
		"out":__DIR__"simiao",
		"enter":"/d/quest/jzzy/baodian",
		"west":"/d/quest/jzzy/jingfang",
	]));
  set("objects",([
          "/d/quest/bawangdao/npc/heshang":1,
	  ]));

	setup();
	replace_program(ROOM);
}

