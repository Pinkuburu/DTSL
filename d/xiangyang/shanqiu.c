
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山丘");
  set ("long", @LONG
这里是座山丘。微风吹来，一阵黄沙微微扬起。这里风景秀丽，山
水如画，空气清新。不时有鸟儿从你的头上飞过。
LONG);

  set("exits", ([ 
 "southeast":__DIR__"shashilu1",
       ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

