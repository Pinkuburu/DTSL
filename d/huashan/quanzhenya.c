
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","全真崖");
  set ("long", @LONG
全真崖，高数十丈，若俯首形状，悬空向里，上不着天，下不着地，
而上面却凿刻着“全真崖”三个大字，每个字皆为两米大小，古朴刚劲，
刻工精绝，每字均填以赤色，望之气势非凡。在如此险恶的地势条件下，
古代的石匠是凭借什么，采用什么办法把字刻上去的，简直让人难以置信。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"shanlu3",
       ]));
  /*
  set("objects",([
	  __DIR__"npc/yao":1,
	  ]));*/
   set("valid_startroom", 1);
   set("outdoors","huashan");
  setup();
 
}
