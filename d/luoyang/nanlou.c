
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"曼清院南楼"NOR);
  set ("long", @LONG
这里是曼清院的南楼。楼上就是上官龙的住处，作为曼清院的主人
上官龙只邀请他认为合适的客人到上面去做客。
LONG);

  set("exits", ([ 
	  "north":__DIR__"huayuan",
	  "up":__DIR__"yashi",
         ]));

  set("valid_startroom", 1);
  setup();
 
}
