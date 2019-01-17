
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北梁山");
  set ("long", @LONG
蜿蜒绵长的北梁山脉位于长安之北，象一道天然的屏障将中原与西
域分割开来。这里是山脉中的一个山峰，从这里向北，能走到回民的部
落，向南走就到了长安了。这里的行人不是很多，四周丛林密布，鲜花
绿草若隐若现，随着山谷里吹来的阵阵清风，传来哗哗的松涛声和一些
淡淡的花香。
LONG);

  set("exits", ([ 
"northdown":__DIR__"shandao4",
"southdown":__DIR__"shandao6",
        ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

