
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huaihebei"
#define TO __DIR__"huaihenan"
#include "/std/shiproom.c"
int do_yell(string arg);
void create ()
{
  set ("short","淮河北岸");
  set ("long", @LONG
这里是淮河的北岸。只有一叶扁舟载来往的行人。这里人比较少，
只见梢公正在那里悠闲地坐着。
LONG);

  set("exits", ([ 

  "northwest":__DIR__"xiaolu1",
         ]));
set("outdoors","yangzhou");
  set("valid_startroom", 1);
  setup();
 
}

