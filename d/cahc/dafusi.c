#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","大府寺");
  set ("long", @LONG
隋唐以来，商贸经济的发达引起了当权者的注意，长安城内就出现
了两个庞大的市场－都会市和利人市，大府寺便是专门管理这些市场而
设的机构，统一管理全国的商贸活动。
LONG);

  set("exits", ([ 
 "east":__DIR__"tianjie3",
 "west":__DIR__"shunyimen",
   ]));
  set("valid_startroom", 1);
  setup();
 
}

