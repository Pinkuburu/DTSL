
inherit ROOM;

void create()
{
	set("short", "成都客店");
	set("long", @LONG       
这是成都客店。这个客店可是成都有名的客店，已经经营了二十几
年。这里每天都有很多的人，所以总是热闹非凡。老板和店小二都前前
后后的忙个不停。这里挂了一个牌子(paizi)。
LONG);

	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五两白银。\n",
	]));

	set("objects", ([
         __DIR__"npc/xiaoer2" : 1,
           
			 
	]));

	set("exits", ([
          "west" : __DIR__"beidajie4",
		"up" : __DIR__"kedian2",
	]));

	setup();
	
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("怎么着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
