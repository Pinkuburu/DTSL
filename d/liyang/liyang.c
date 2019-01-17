inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "黎阳");
	set("long", @LONG
这就是军事重镇黎阳。黎阳是兵家必争之地，向北可以进攻河北，
山东，向西可图长安，和荥阳成犄角之势，退可守河南，进可攻洛阳，
以图荆襄。
LONG );
	set("outdoors", "liyang");
	set("exits", ([
		"north" : __DIR__"dadao4",
		"south" : __DIR__"dadao6",
                "west" : __DIR__"dadao5",
                "east" : __DIR__"qingshilu",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
	setup();
}
