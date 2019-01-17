
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山谷");
  set ("long", @LONG
这里是一条终南山上的一个山谷。大唐到终南山打猎的行宫就在这
里，四周丛林密布，鲜花绿草若隐若现，随着山谷里吹来的阵阵清风，
传来哗哗的松涛声和一些淡淡的花香。
LONG);

  set("exits", ([ 
"westup":__DIR__"shandao2",
"southup":__DIR__"shandao7",
"east":__DIR__"xinggong",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

