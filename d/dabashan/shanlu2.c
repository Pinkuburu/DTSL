
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是大巴山的一条山路。北边是一个山脊，西边有一个树林，南
边有很多山洞，也不知道里面有没有盗贼。
LONG);

  set("exits", ([ 

   "southwest":__DIR__"shulin",
   "enter":__DIR__"shandong1",
   "north":__DIR__"shanji1",
         ]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

