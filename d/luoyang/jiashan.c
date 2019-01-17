
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"假山"NOR);
  set ("long", @LONG
这里是一座假山。此处假山形状奇特，仔细看去，隐约有着黄山之
姿，泰山之伟，华山之险。假山上还有一个小凉亭，上面挂了个牌匾，
写着“五岳亭”。
LONG);

  set("exits", ([ 
  
  "north":__DIR__"huangchengnan",

  "south":__DIR__"changlang",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

