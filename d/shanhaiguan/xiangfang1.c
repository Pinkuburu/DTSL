// /d/gaoli/xiangfang1.c
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "厢房");
	set("long", @LONG
在屋的东边靠墙的位置有一趟木版床，一些帮众光着膀子，做在木
板床上，五，十的喊着，原来是在赌钱。
LONG
	);
set("exits", ([
                "south" : __DIR__"siheyuan",       
	]));
       setup();
	replace_program(ROOM);
}	
