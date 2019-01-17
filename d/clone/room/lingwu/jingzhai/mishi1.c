
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山洞");
  set ("long", @LONG
这是一个小山洞，虽然外面冰天雪地，但这里却温暖如春。只见洞
旁立着一个小石碑，上面写着：「白云洞」三个字。洞中央放着一个石
桌子和几把石凳子，同外面的世界相比，这里真是别有洞天。
LONG);

  set("exits", ([ 
 "out":__DIR__"songshu",
 "west":__DIR__"mishi2",
        ]));
  set("objects",([
     __DIR__"fan":1,
     ]));
  
  set("valid_startroom", 1);
  setup();
 
}

