inherit ROOM;
void create()	
{
	set("short", "当铺");
	set("long", @LONG
你走进当铺，正间屋里有一个大柜台，所有要典当的东西，都要由
柜台的窗口送过去，交给里头的供奉进行估价。
LONG
	);
set("exits", ([
                "north"  :__DIR__"xidajie",
	]));
         set("objects", ([
		 __DIR__"npc/gongfeng" : 1
	]));
       setup();
	replace_program(ROOM);
}	
