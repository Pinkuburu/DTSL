
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short",HIM"断路崖"NOR);
  set ("long", @LONG
你走到这里，突然发现前方已经没路了，一座高几乎上千米的巨崖挡在
面前，似乎连神仙都难以逾越，俗话说，”自古华山一条路“，果然没错，
看来，要想上华山，只能退回去寻找那条正路了。
LONG);

  set("exits", ([ 
//"eastup":__DIR__"shanlu5",
"southdown":__DIR__"shanlu3",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

