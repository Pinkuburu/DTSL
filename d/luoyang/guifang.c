
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"闺房"NOR);
  set ("long", @LONG
尚秀芳的闺房并没有想象中那么华丽，也没有一丝多余的装饰品，
反而让人感觉象是修真之士的卧室。
LONG);

  set("exits", ([ 
	  "down":__DIR__"beilou",
  ]));

  set("valid_startroom", 1);
  setup();
 
}
