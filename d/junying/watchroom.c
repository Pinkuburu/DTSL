//观演台watchroom.c
inherit ROOM;
void create()
{
set("short","观演台");
set("long",@LONG
你大步走上观演台。顺眼向下望去，立刻被台下气势震慑。士兵们士气
如虹，一进一退，有板有眼，杀声震天动地。观演台中坐一人，此人正是华
亭守将张天恩，其当年全歼太湖水盗，声名大振。他看到你上了观演台，眉
头一皱，紧盯着你，眼光锐利，似乎要看穿你的心。
LONG);
set("exits",([
"down":__DIR__"showroom",
]));
set("objects",([
__DIR__"npc/zhangtian":1,
__DIR__"npc/wujiang":1,
]));
setup();
}
