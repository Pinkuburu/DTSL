
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","武馆大厅");
  set ("long", @LONG
这里是武馆大厅，正中靠北摆着一张八仙桌，桌上供着关公的神位，
旁边放着两个青瓷花瓶，插着几支孔雀翎，墙上写着大大的一个“武”
字武馆主人早些年在江湖上闯荡，现今洗手隐退,在长安开起了这间武
馆。
LONG);

  set("exits", ([ 
 
 "southdown":__DIR__"wuguan1",
        ]));
  set("objects",([
	  __DIR__"npc/gongsun":1,
	  ]));
set("valid_startroom", 1);
  setup();
 
}

