
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"观"HIR"花"HIW"园"NOR);
  set ("long", @LONG
这里是洛阳皇宫的观花园。虽然不及御花园大，但是这里的花品种
繁多，每天都有花匠在这里护养，所以这里许多花竟相开放，五彩缤纷。
这里是皇上和妃子们经常来的地方。
LONG);

  set("exits", ([ 
  "south":__DIR__"xidian",
  "north":__DIR__"shijie2",
         ]));
  set("objects",([
   __DIR__"npc/gongnv1":2,
   ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

