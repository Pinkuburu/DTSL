
#include <ansi.h>
#include <job_money.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"大殿"NOR);
  set ("long", @LONG
这里是老君观的正殿。正面放着太上老君的石像，但是已经落满了
灰尘。旁边放着几个蒲团和木鱼，但也被尘土所覆盖以久了。一阵微风
吹过，一股萧瑟荒凉之意油然而生。
LONG);

  set("exits", ([ 

  "south":__DIR__"tingyuan",
        ]));

  set("valid_startroom", 1);
  setup();
 
}

