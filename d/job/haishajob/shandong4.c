
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIB"山洞"NOR);
  set ("long", @LONG
这里是一个山洞，黑黑的，几乎看不到有什么出路。据说最近这里
来了很多抢宝藏的人。前面呼喝之声已经很近了。
LONG);

  set("exits", ([ 
 "enter":__DIR__"shandong5",
 "out":__DIR__"shandong3",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
