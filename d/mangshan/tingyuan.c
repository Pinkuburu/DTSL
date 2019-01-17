
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"庭院"NOR);
  set ("long", @LONG
这里是老君观的庭院。正中央立了一个大铜鼎，香气缭绕。北面是
座大殿。这里气氛肃穆，但是难以掩盖一种萧瑟荒凉的气氛，不时有鸟
儿从你的头上飞过。
LONG);

  set("exits", ([ 

  "out":__DIR__"door",
 "north":__DIR__"dadian",
 "east":__DIR__"fantang",
 "west":__DIR__"jingfang",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

