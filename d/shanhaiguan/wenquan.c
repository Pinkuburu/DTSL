// /d/shanhaiguan/dadao1.c
// Room in 山海关
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "饮马温泉");
	set("long", @LONG
进入卞楼，竟是个宽敞可窖近十张大圆臬的饭堂，主楼後院
是个大花园，乃著名的饮马温泉所在不规则的天然温他热气腾升，
立时把布置简朴的饭堂提升为仙界福地。
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "east":__DIR__"kezhan",  
                	]));
       setup();
	replace_program(ROOM);
}
