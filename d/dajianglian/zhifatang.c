
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIR"执法堂"NOR);
  set ("long", @LONG
这里是大江联分舵的执法堂，这里立着一尊塑像，看起来面色严肃，
没有半分的笑容。大江联的弟子犯了错误，都到这里来处罚。
LONG);

  set("exits", ([ 
	  "west":__DIR__"caodi",
	     ]));
set("outdoors","dajiang");
/*  set("objects",([
	  "/d/job/banghuijob/dajiang":1,
          ]));*/
  set("valid_startroom", 1);
  setup();
 
}

