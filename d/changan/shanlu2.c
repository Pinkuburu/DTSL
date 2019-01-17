
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。两旁是茂密的草丛，这里几乎没有什么人，阵阵
风吹来，传来远处几声马嘶鸣的声音。只听扑棱一声，只见一只野兔从
旁边的草丛中跑了出来。
LONG);

  set("exits", ([ 
"northwest":__DIR__"shanlu1",
"southeast":__DIR__"tulu1",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

