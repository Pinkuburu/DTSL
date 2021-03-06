inherit ROOM;

void create()
{
	set("short", "梁都客栈");
	set("long", @LONG       
这是梁都客栈，老板生意非常兴隆。外地游客多选择这里落脚，你
可以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接待
着南腔北调的客人。当你走了进来，店小二连忙迎上前去。客栈正面的
墙上挂着一块醒目的牌子(paizi)。
LONG
	);

	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五两白银。\n",
	]));

	set("objects", ([
         __DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
          "south" : __DIR__"dongdajie",
		"up" : __DIR__"kedian2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("gived_money") && dir == "up" )
		return notify_fail("怎么着，想白住啊！\n");

	if ( me->query_temp("gived_money") && dir == "south" )
		return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
