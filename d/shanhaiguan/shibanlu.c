// /d/gaoli/shibanlu
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "石板路");
        set("long", @LONG
地面都是由青石铺成，道上静悄悄的，东南是山海关的中心广场，
北边是山海关第一大帮"北霸帮"的总舵口。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
            	"southeast" : __DIR__"guangchang",
                "north" : __DIR__"beibabang",
	]));
       setup();
	replace_program(ROOM);
}
