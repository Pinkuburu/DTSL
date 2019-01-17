
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","莲花坪");
  set ("long", @LONG
由无上洞循山脚而行，西面山岩一面坡下，石上被水冲刷成许多沟，
是三峰之间形成的洼地，面积广大，统称莲花坪。洼地上有许多石沟，为
数二十八个，叫二十八宿潭。自南而北，累累如贯珠。坪四周松林荫翳，
景色清幽。上有玉井，下有玉泉，一曲流水，融会贯通，浑然一体，可谓
巧遇巧合。玉井附近原建有玉井楼，园径半之，水味醰美。
LONG);

  set("exits", ([ 
 "eastdown":__DIR__"wushangdong",
 "southup":__DIR__"cuilinggong",
       ]));
  /*set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
