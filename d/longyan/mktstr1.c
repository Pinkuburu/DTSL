// Room: /d/longyan/mktstr1.c

inherit ROOM;

void create()
{
	set("short", "龙眼村集市");
	set("long", @LONG
这里就是龙眼村的集市一条街了。一条大道由东向西方延
伸，道上人来人往，车水马龙，热闹至极。只见道路两旁到处
是叫卖的小贩。向东走就是龙眼村的市中心——槐树下。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : "/d/wiz/vocation",
  "east" : __DIR__"center",
  "west" : __DIR__"mktstr2",
]));

	setup();
	replace_program(ROOM);
}
