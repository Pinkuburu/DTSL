// /d/yazhang/dongmen.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "东门");
	set("long", @LONG
东突厥是草原的霸主，故定襄城建的非同一般，城墙足有三丈高，
城门建的又高又大，足可让马并行。一条大道通向山海关。
LONG
	);
set("outdoors", "/d/yazhang");
set("exits", ([
"northeast" : "/d/saiwai/shop",
                  "west" : __DIR__"dongdajie1",    
	]));
       setup();
	replace_program(ROOM);
}	
