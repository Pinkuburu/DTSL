
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西内苑");
  set ("long", @LONG
西内苑建筑布局对称而不呆板，舒展而不零散。以园中殿为中心，
两边均衡地布置各式建筑近二十座，无论是依墙而建还是亭台独立，均
玲珑别致，疏密合度。东面是齐王元吉的住处，西面是公主李秀宁的香
闺。
LONG);

  set("exits", ([ 
 "north":__DIR__"waixuanmen",
 "south":__DIR__"qingshilu2",
 "east":__DIR__"wudedian",
 "west":__DIR__"yiyuxuan",
        ]));
  set("outdoors","changan");
  set("valid_startroom", 1);
  setup();
 
}

