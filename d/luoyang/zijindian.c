
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit ROOM;

void create ()
{
  set ("short",HIY"紫金殿"NOR);
  set ("long", @LONG
这里就是皇帝每天朝政的紫金殿了。这里气氛庄严肃穆。整个大殿
显得金碧辉煌，大殿的尽头就是人人欲得到的天子宝座了。大殿的两旁
是两个高大的柱子，各自盘旋着金龙。柱子的两边垂下一些白纱，许多
护卫就站在后边，保护着皇上的安全。
LONG);

  set("exits", ([ 
  "east":__DIR__"dongdian",
  "west":__DIR__"xidian",
  "out":__DIR__"shijie1",
         ]));

  set("objects",([
   __DIR__"npc/gongnv1":1,
   __DIR__"npc/taijian1":1,
   ]));
  set("valid_startroom", 1);
  setup();
 
}

