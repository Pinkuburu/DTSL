
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"天津桥"NOR);
  set ("long", @long
天津晓月乃洛阳八景之首，最迷人是夜阑人静，明月挂空之时，偕
美来此把臂同游，个中况味，当是一言难述。
long);

  set("exits", ([ 
  

  "northdown":__DIR__"tianjinqiao1",
  "southdown":__DIR__"tianjinqiao3",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

