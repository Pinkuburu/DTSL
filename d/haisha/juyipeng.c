
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","聚义棚");
  set ("long", @LONG
这里是海沙帮的聚义棚。正面有一个大牌子(pai) ，上面写着一个
鲜红的[义]字。这里庄严肃穆，出入这里的人都是小心翼翼。
LONG);

  set("exits", ([ 
 "northwest":__DIR__"shalu",
         ]));
  set("objects",([
	  __DIR__"npc/bangzhu":1,
	  ]));
set("no_clean_up",1);
  set("item_desc",([
     "pai":HIR"    义\n\n\n"NOR,
                ]));                               
  set("valid_startroom", 1);
  setup();
  "/obj/sboard/haisha_b.c"->foo();
 
}

