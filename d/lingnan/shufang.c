
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","书房");
  set ("long", @LONG
这里是宋家堡的堡主宋缺的书房。这里放着很多武功类的书籍。书
房看起来很干净，似乎刚刚有人打扫过。书架上放了很多书籍，不禁有
武学方面的，还有四书、五经等书籍。
LONG);

  set("exits", ([ 

  "south":__DIR__"xilang2",
       ]));

  set("valid_startroom", 1);
  
  setup();
 
}

