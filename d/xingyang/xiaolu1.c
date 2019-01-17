inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
此间是通向静念禅院后山的一条小路。向东可以到达金墉城，你静
下心来，驻足倾听，似乎能听到西面传来的诵经的声音。
LONG );

	set("exits", ([
                        "northeast"      : __DIR__"tulu9",
                        "southwest"      : __DIR__"xiaolu2",

	]));
	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



