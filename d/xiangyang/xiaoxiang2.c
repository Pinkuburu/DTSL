
#include <ansi.h>
#include <job_money.h>
inherit ROOM;


void create ()
{
  set ("short","小巷");
  set ("long", @LONG
这里是小巷。普通的百姓是不敢来这里的。只见这里赌博声不绝，
不时出现叫骂打仗的声音。还有一群黑衣人正在那里擦拭着钢刀，似乎
正在商量去抢劫盐车。巷子深处有几个壮汉正在勒索一个书生模样人的
钱财。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"xiaoxiang1",
        ]));
  set("outdoors","xiangyang");
set("valid_startroom", 1);
  setup();
 
}

