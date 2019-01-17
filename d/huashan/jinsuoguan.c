
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","金锁关");
  set ("long", @LONG
这里可清晰看到东峰、南峰和西峰，三峰之间有一山间小盆地——
莲花坪，三峰之水汇于坪中，小洼地积水而成玉井。每逢雨季，玉井的
水在东西两峰间溢流而出形成飞流直下的瀑布，成为华山胜景之一。
LONG);

  set("exits", ([ 
 "northdown":__DIR__"wuyunfeng",
 "westup":__DIR__"wushangdong",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
