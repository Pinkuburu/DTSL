
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
你正走在一条崎岖不平的山路上，偶尔听到一阵阵的野兽叫声，头
顶有一些不知名的小鸟在跳来跳去，四周丛林密布，鲜花绿草若隐若现，
随着山谷里吹来的阵阵清风，传来哗哗的松涛声和一些淡淡的花香。由
于近来兵荒马乱，所以几乎没有人来这里。这里是邙山的一座山头。向
东远远望去，可以看到有一座庙宇。
LONG);

  set("exits", ([ 

  "westdown":__DIR__"shanlu3",
 "eastdown":__DIR__"shanlu5",
         ]));

  set("valid_startroom", 1);
  setup();
 
}

