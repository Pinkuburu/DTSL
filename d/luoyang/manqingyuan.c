
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"曼清院"NOR);
  set ("long", @LONG
这里是洛阳最大的青楼曼清院。每天这里的人来往不绝。有几个漂
亮的女子在这里拉客。这里也是洛阳最大的帮派洛阳帮的势力范围。曼
清院的主人就是洛阳帮的帮主上官龙。
LONG);

  set("exits", ([ 
	  "east":__DIR__"beijie3",
	  "enter":__DIR__"huayuan",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}
