
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里条小路。一阵风吹来，卷起阵阵尘土。不时有人骑着马从你的
身旁驰过。向北望去，可以隐约看见扬州的城门了。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"xiaolu2",
 "south":"/d/outyang/dalu1",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

