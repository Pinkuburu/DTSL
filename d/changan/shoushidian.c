#include <ansi.h>
inherit ROOM;

int do_zuan(string arg);
void create ()
{
  set ("short","首饰店");
  set ("long", @LONG
这是一间专门卖女人用的首饰的店铺，在长安非常有名，前来光顾
的大都是姑娘媳妇，店铺中摆放了一张长长的木桌，上面摆着大大小小
的盒子，盒子里面都是闪闪发光的各种首饰。一个胖胖的老板正在招呼
进来的顾客。
LONG);

  set("exits", ([ 
 "west":__DIR__"xishidongjie1",
      ]));
  set("objects",([
         __DIR__"npc/zhubao-boss2":1,
         ]));
  set("valid_startroom", 1);
  setup();
 
}
