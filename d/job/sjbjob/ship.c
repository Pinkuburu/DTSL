
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","巨舟");
  set ("long", @LONG
这里是一艘巨舟，航行与扬州与高丽之间。这里有很多水手，忙来
忙去。船上坐着很多高丽人，他们正在用高丽语聊着天。
LONG);

 set("outdoors","ship");
  set("valid_startroom", 1);
  setup();
 
}

