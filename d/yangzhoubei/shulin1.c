
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","树林");
  set ("long", @LONG
这里一片树林。树木茂盛，遮住了阳光。不时有人成群结队走过。
据说这里经常有盗匪出没。你不禁加快了脚步。
LONG);

  set("exits", ([ 
 "north":__DIR__"xiaoxi1",
 "south":__DIR__"caodi2",
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

