
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","假山");
  set ("long", @LONG
你面前矗立着一座巨大的假山，一道片练也似的银瀑从假山边泻将
下来，注入前面的一座大池塘中，池塘底下想是另有泻水通道，是以塘
水却不见满溢。皇宫为建这个花园，也不知花费了多少人力、物力。
LONG);

  set("exits", ([ 
 "east":__DIR__"yuhuayuan",
         ]));
  
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

