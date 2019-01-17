
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","少府监");
  set ("long", @LONG
少府监是朝廷设立的中央机构，专门掌管织造宫廷使用器物的手工
业作坊。“少府监”下设有五部分：中尚方、左尚方、右尚方、仿染方和
掌冶方，其工匠有一万九千多人。
LONG);

  set("exits", ([ 
 "west":__DIR__"tianjie3",
 "east":__DIR__"jingfengmen",
        ]));
  

  
  set("valid_startroom", 1);
  setup();
 
}

