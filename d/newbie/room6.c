
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","当铺篇");
  set ("long", @LONG
这里教会你如何在泥巴中与当铺的老板进行交易！首先你要到一个
当铺去了。在当铺中你可以使用以下命令：
list ：看当铺中有什么东西卖
value：对于你想卖的东西进行估价
buy  ：从当铺中买东西
sell : 在当铺卖东西

>list
你要看哪类物品？
兵器[weapon]、盔甲[armor]、矿石[iron]、药物[medicine]、其他[other]。

这时你要使用 list 具体项目来查看了。
LONG);

  set("exits", ([ 
 "east":__DIR__"room4",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

