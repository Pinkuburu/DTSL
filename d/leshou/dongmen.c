// /d/zhuojun/dongmen.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "东门");
	set("long", @LONG
这是乐寿的东城门，再向西走就进入了乐寿城，因为现在天下大乱，
所以把门的士兵对来往过路的人盘查得非常严格。
LONG
	);
set("outdoors", "/d/zhuojune");
set("exits", ([
		"east" :__DIR__"eroad1",
                "west"  :__DIR__"dongdajie1",
	]));
       set("objects",([
                __DIR__"npc/guanbing" : 2,
                __DIR__"npc/wujiang" : 1,
        ]));
       setup();
	replace_program(ROOM);
}	
