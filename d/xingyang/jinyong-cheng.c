inherit ROOM;

void create()
{
	set("short", "金墉");
	set("long", @LONG
这里就是金墉城了，金墉位于荥阳之西南，大河之北岸，与河阳成
犄角之势，自古为兵家必争之地，现在天下大乱，群雄并起，这里也几
经易手，无论是谁，这里都屯有重兵，又因为这里是军事重地，所以对
来往的行人盘查的十分严格。	
LONG );

	set("exits", ([
               "east"      : __DIR__"heyang",
               "north"      : __DIR__"tulu4",

	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



