// /d/shanhaiguan/dadao1.c
// Room in 山海关
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "饮马驿");
	set("long", @LONG
你走进楼里，两厢客房足有五十间之多，天井周围是环浇的回廊，
置有数组各七、八张椅臬供人歇息谈天，自有其懒闲写意的味儿，天井
中心是个宽达两丈的大水池。
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "east":__DIR__"yinmayi",  
                "west":__DIR__"wenquan",
                  "north":__DIR__"beifang",  
                 "south":__DIR__"nanfang",  
                	]));
       setup();
	replace_program(ROOM);
}
