
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","小楼");
  set ("long", @LONG
这里是座小楼。据说石青璇曾经住在这里。四周围杆花纹奇特，必
定是出自成都著名工匠之手。床上的被褥还叠得整整齐齐，桌子和床上
还是一尘不染，看来必是每天有丫鬟来这里打扫。
LONG);

  set("exits", ([ 
  
	  "northwest":__DIR__"xiaojing3",
     ]));
  set("valid_startroom", 1);
  setup();
 
}
