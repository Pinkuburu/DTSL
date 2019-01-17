
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兵器铺");
  set ("long", @LONG
这里是一家兵器铺。由于战乱，这里的生意更是好做了。这里挂着
一个牌子 (pai)。襄阳的铁匠最近开始招收学徒，所以他的生意更是好
做。只见铁匠一边在做示范，旁边的几个弟子在认真地听着。熊熊地炉
火照得你脸有些发热了。
LONG);

  set("exits", ([ 
 "south":__DIR__"xidajie2",
 "enter":__DIR__"tiejianggh",
       ]));
  set("objects",([
      __DIR__"npc/tiejiang":1,
      "/u/kouzhong/walker":1,
	  ]));
  set("item_desc",([
	  "pai":"本店现在招收学徒，有愿意者可速来。
             学徒也自行打造兵器，目前学徒可以
             打造的兵器类型为：
             剑类：sword
             刀类：blade
             杖类：staff
             锤类：hammer
             鞭类：whip
             斧类：axe
             叉类：fork
             枪类：spear             
             匕首类：dagger\n",
			 ]));
	  
  set("valid_startroom", 1);
  setup();
 
}
/*
int valid_leave(object me,string dir)
{
        if(me->query("vocation")!="铁匠" && dir=="enter")
                return notify_fail("你不是铁匠，不能进入铁匠工会!\n");
                return ::valid_leave(me,dir);
                return 1;
}
*/

