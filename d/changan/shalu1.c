
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short","沙路");
  set ("long", @LONG
这里是一条沙路。大风吹起阵阵的狂沙。东边不远就是河南的洛阳
了。远处一片荒芜的田地，由于常年的战乱，民不聊生，一股苍凉之意
油然而生。
LONG);

  set("exits", ([ 
"northwest":__DIR__"dalu2",
"southeast":__DIR__"shalu2",
       ]));
 set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

