
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","揽星阁");
  set ("long", @LONG
这里是菀兰楼的二楼。阁中放着一张小木桌，桌上放着精美
点心。旁边有一张竹床，屋顶开着天窗，夫妇二人常躺在床上看
着满天星星，对着流星许愿。打开窗户就可以看到扬州的美丽景
色，真是天上人间。
LONG);

  set("exits", ([ 
 "down":__DIR__"yll",
      ]));
 set("valid_startroom", 1);
  setup();
 
}

