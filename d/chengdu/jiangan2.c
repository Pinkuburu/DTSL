
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangan2"
#define TO __DIR__"jiangan1"
#include "/std/shiproom.c";
void create ()
{
  set ("short","长江南岸");
  set ("long", @LONG
这里是长江的南岸。过了长江，就到了四川的境地了。眼前江水滚
滚，只有一叶扁舟摆渡来往的行人。
LONG);

  set("exits", ([ 

  "south":__DIR__"shalu1",
         ]));
set("outdoors","jiang");
  set("valid_startroom", 1);
  setup();
 
}

