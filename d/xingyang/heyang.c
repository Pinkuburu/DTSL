inherit ROOM;

void create()
{
	set("short", "河阳");
	set("long", @LONG
这里就是河阳城了，河阳位于荥阳之西南，大河之北岸，与金墉成
犄角之势，自古为兵家必争之地，现在天下大乱，群雄并起，这里也几
经易手，无论是谁，这里都屯有重兵，又因为这里是军事重地，所以对
来往的行人盘查的十分严格。	
LONG );

	set("exits", ([
               "west"      : __DIR__"jinyong-cheng",
               "northwest"      : __DIR__"tulu4",
               "south"      : __DIR__"tulu5",		
	]));

 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



