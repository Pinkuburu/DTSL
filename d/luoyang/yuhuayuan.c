
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"御"HIR"花"HIY"园"NOR);
  set ("long", @LONG
这里是洛阳皇宫的御花园。这里的花品种繁多，每天都有花匠在这
里护养，所以这里许多花竟相开放，五彩缤纷。这里是皇上和妃子们经
常来的地方。
LONG);

  set("exits", ([ 
  
  "east":__DIR__"xilang2",
  "north":__DIR__"qingong",

         ]));
  set("objects",([
   __DIR__"npc/gongnv1":2,
   ]));
set("outdoors","luoyang");
  
  set("valid_startroom", 1);
  setup();
 
}

