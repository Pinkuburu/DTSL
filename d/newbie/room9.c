
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","杀手篇");
  set ("long", @LONG
此类职业或许对PK是最有用的吧！ 
杀手向杨虚彦学习 顽石诀（心法）和影子剑法。 
xue yang yingzi-jianfa 
xue yang wanshi-jue 
顽石诀有两个用处：execute(shizhan) huanmo(幻魔):可以在3 秒内使
气势 达到顶峰，迅速战斗，但是气势也维持几秒就降零了。 
execute(shizhan) wuxing(无形):可以使自己处于隐身状态，别人看不
到你，不过在此时间内不能走动。一但进入战斗状态，则解除隐身效果。 
杀手还可以在兵器上涂抹毒药。 
杀手还可以使用暗杀 (ansha)命令来暗杀相隔房间的敌人，一次三招。
此外，杀手对于寻找好的矿石和药材有更大的优势。
LONG);

  set("exits", ([ 
 "east":__DIR__"room7",
 //"west":__DIR__"room9_1",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

