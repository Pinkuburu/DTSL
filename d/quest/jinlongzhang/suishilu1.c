
inherit ROOM;


void create ()
{
  set ("short","碎石路");
  set ("long", @LONG
这里是条碎石路，弯弯曲曲的，看不到尽头。路的右边有一
条小溪，溪水清澈见底。左边是一些花草树木，散发着淡淡的清
香。
LONG);

  set("exits", ([ 

  "southeast":"/d/xiangyang/tree1",
  "northwest":__DIR__"shijie",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

