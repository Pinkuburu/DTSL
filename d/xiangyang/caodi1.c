
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","冷水滩");
  set ("long", @LONG
这里是就是冷水滩。再往南边走不远就是岭南了。这里树木稀少，
只有远处有一片稀疏的草地。
LONG);

  set("exits", ([ 

  "northeast":__DIR__"tree2",
  "southeast":"/d/lingnan/caodi1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","hunan");
  setup();
 
}

