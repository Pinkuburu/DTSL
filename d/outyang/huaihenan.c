
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huaihenan"
#define TO __DIR__"huaihebei"
#include "/std/shiproom.c"
void create ()
{
  set ("short","淮河南岸");
  set ("long", @LONG
这里是淮河的南岸。只有一叶扁舟载来往的行人。这里人比较少，
只见梢公正在那里悠闲地坐着。
LONG);

  set("exits", ([ 

  "south":__DIR__"xiaolu2",
         ]));
set("outdoors","yangzhou");
  set("valid_startroom", 1);
  setup();
 
}

