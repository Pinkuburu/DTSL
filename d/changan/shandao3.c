
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条北梁山山脉中的山路。这里的行人不是很多，四周丛林
密布，鲜花绿草若隐若现，随着山谷里吹来的阵阵清风，传来哗哗的松
涛声和一些淡淡的花香。
LONG);

  set("exits", ([ 
"northeast":"/d/taiyuan/road8c",
"southup":__DIR__"shandao4",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

