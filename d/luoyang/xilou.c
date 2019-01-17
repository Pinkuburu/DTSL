
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"曼清院西楼"NOR);
  set ("long", @LONG
这里是曼清院的西楼，主要是来此玩乐的客人留宿的地方，虽然经
常能听到各种嬉笑声音从这里传出来，但是又有多少人能了解这些笑声
后所隐藏的屈辱和辛酸？
LONG);

  set("exits", ([ 
	  "east":__DIR__"huayuan",
	  "up":__DIR__"kefang0",
         ]));

  set("valid_startroom", 1);
  setup();
 
}
