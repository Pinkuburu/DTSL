// /d/gaoli/beibabang.c
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "北霸帮");
        set("long", @LONG
这里是山海关第一大帮北霸帮的总堂口，漆黑的大门紧闭着，大门
上有三个斗大的金字"北霸帮"，门两旁一对石狮子。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
            	"south" : __DIR__"shibanlu",
	]));
       setup();
	replace_program(ROOM);
}
