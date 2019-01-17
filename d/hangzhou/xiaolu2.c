
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是条小路，路的两旁种了很多柳树。四周丛林密布，鲜花绿草
若隐若现，随着山谷里吹来的阵阵清风，传来哗哗的松涛声和一些淡淡
的花香，东边不远处就是西湖了。不时有游客到从这里走过。
LONG);

  set("exits", ([ 
 "east":__DIR__"xiaolu1",
 "southwest":__DIR__"xiaolu3",
        ]));
 set("objects",([
	 __DIR__"npc/youke3":1,
	 ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

