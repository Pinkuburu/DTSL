
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","宏发粮行");
  set ("long", @LONG
这是一家专门买卖粮食的商行，店里有不少的伙计都在忙碌，老板
做在柜台后面用算盘噼里啪啦的算着账，脸上不时露出心满意足的微笑。
LONG);

  set("exits", ([ 
 "west":__DIR__"xishixijie3",
        ]));
  set("objects",([
         __DIR__"npc/liangdian-boss":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}

