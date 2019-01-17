
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","总管府");
  set ("long", @LONG
这里是扬州城的总管尉迟胜的府第。门的正上方挂着一个镶着金边
的大牌子，上面写着总管府三个大字。门口有几个官兵把守着，威风凛
凛地站在那里，打量着来往的行人。平时很少有人在这里停留。
LONG);

  set("exits", ([ 
 "south":__DIR__"xidajie2",
 "enter":__DIR__"neiting",
        ]));
  
  set("valid_startroom", 1);
  setup();
 
}

