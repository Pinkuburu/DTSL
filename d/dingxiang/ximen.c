// /d/yazhang/ximen.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "西门");
	set("long", @LONG
东突厥是草原的霸主，故定襄城建的非同一般，城墙足有三三丈高，
城门建的又高又大，足可让马并行。
LONG
	);
set("outdoors", "/d/yazhang");
set("exits", ([
                  "east" : __DIR__"xidajie1",  
                  "west" : "/d/suiye/caoyuan",    
	]));
       setup();
	replace_program(ROOM);
}	
