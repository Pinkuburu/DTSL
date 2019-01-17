
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","卧牛台");
  set ("long", @LONG
卧牛台是山腰上一块不大的地方，眼前，华山的奇峰峭壁，悬崖密
林，深渊危谷，尽收眼底。卧牛台上的那个“臣牛石”，就是当年老君
的青牛，传说青牛在犁完犁沟后，看到华山景色壮丽秀美，便化为石牛，
永远地留在了华山之上。
LONG);

  set("exits", ([ 
 "westdown":__DIR__"konglingfeng",
 "northup":__DIR__"yuntaifeng",
 "southup":__DIR__"canglongling",
       ]));
  set("objects",([
	  __DIR__"npc/tucaizhu":1,
	  ]));
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
