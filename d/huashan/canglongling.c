
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","苍龙岭");
  set ("long", @LONG
苍龙岭属华山著名险道之一。因岭呈苍黑色，势若游龙而得名。岭
西临青柯坪深涧，东临飞鱼岭峡谷，长约百余米，宽不足三尺，中突旁
收，游人在上面行走，心旌神摇，如置云端，惊险非常。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"woniutai",
 "southup":__DIR__"wuyunfeng",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
