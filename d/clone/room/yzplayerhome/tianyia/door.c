
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short","庄门");
	set("long", @LONG
你转过一丛茂密的花丛, 猛然间, 只见一座红檐绿瓦, 小巧
玲珑的庄院矗利在灿澜的花丛中。庄门大匾上赫然写着「弈花山
庄」四个金光闪闪的大字。
LONG);
    set("exits", ([
	        "east" : "/d/clone/room/yzplayerhome/nandajie4",
	        "north":__DIR__"shanzhuang",
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
