// /d/shanhaiguan/dadao1.c
// Room in 山海关
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "饮马驿");
	set("long", @LONG
饮马驿位于峡谷一侧的山势高处，背傍高山，颇有占山为上的山紊
味道，具备军事防御的力量。一座两层高的士楼以正圆形高达三丈的石
砌围墙包环维围墙就由士褛两侧开展，环抱出敞问的人广场，亦是车马
停驻的地方。
LONG
        );
set("outdoors", "/d/shanhaiguan");
set("exits", ([
                "eastdown":__DIR__"qingshilu",  
                "west":__DIR__"kezhan",
                	]));
       setup();
	replace_program(ROOM);
}
