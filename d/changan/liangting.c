
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","小凉亭");
  set ("long", @LONG
这里是座凉亭，供游客休息之用。你站在凉亭里面，古城长安尽收
眼底，你抬目望去，却见终南山上的树木郁郁葱葱。果真是一个欣赏风
景绝佳的场所。
LONG);

  set("exits", ([ 
 "east":__DIR__"shanyao",
         ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}
