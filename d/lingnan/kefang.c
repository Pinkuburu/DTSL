
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","客房");
  set ("long", @LONG
这里是宋家堡的客房。床上的被褥叠得整整齐齐，平时有宋家堡的
丫鬟来这里打扫房间，所以这里收拾得很干净，桌子和床都是一尘不染。
不过看样子，好象很久没有人住过了。
LONG);

  set("exits", ([ 

  "west":__DIR__"xiaojing1",
      ]));
  set("sleep_room",1);
 
  setup();
 
}

