
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIB"地道"NOR);
  set ("long", @LONG
这里是一个地道，黑黑的，伸手不见五指。这里非常狭窄，你只能
匍匐着前进了。前面好象是个密室，不知道里面是什么人。
LONG);

  set("exits", ([ 
 "in":__DIR__"mishi",
"west":__DIR__"didao2",
      ]));
  set("no_select",1);
  set("valid_startroom", 1);
  setup();
 
}
