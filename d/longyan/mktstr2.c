// Room: /d/longyan/mktstr2.c

inherit ROOM;

void create()
{
	set("short", "龙眼村集市");
	set("long", @LONG
这里就是龙眼村的集市一条街了。一条大道由东向西方延
伸，道上人来人往，车水马龙，热闹至极。只见道路两旁到处
是叫卖的小贩。北面是“紫仁堂”药铺，而南面就是远近闻名
的“有间客栈”了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"hotel",
  "east" : __DIR__"mktstr1",
  "north" : __DIR__"drugstore",
]));

	setup();
	replace_program(ROOM);
}
