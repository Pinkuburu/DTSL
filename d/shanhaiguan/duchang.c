// /d/gaoli/duchang
// Room in 山海关
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "赌场");
	set("long", @LONG
这里是一家赌坊。当夜幕降临后，这里就格外热闹。大厅里有赢的
欢笑声，也有输的懊悔声。这里实在是一个奢侈的地方，随时都在为各
式各样奢侈的人，准备着各式各样奢侈的享受。
LONG	
       );
set("exits", ([
                "north":__DIR__"dongdajie",    
	]));
       setup();
       replace_program(ROOM);
}
