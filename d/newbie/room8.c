
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","铁匠篇");
  set ("long", @LONG
到襄阳的铁匠铺，qiuzhi tie就可以成为铁匠。可以向上官先生学
习锻造技术。xue shangguan duanzao-jishu，锻造技术只能学到100
级，以后靠打造东西提高。你可以向铁匠询问“分支”来确定自己的铁
匠分支。
目前铁匠有三个分支： 
1 打造兵器类(weapon) 
2 锻造盔甲、药鼎类(armor) 
3 打造可以涂毒兵器类(poison)。 
你可以使用choose 来选择。如 choose weapon 
每个分支都有自己的作用，具体还是看看 help vocation吧！
LONG);

  set("exits", ([ 
 "west":__DIR__"room7",
 "east":__DIR__"room8_1",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

