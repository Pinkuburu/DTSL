
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","崇教殿");
  set ("long", @LONG
崇教殿是太子学习的地方，很多当代的大家都来这里给太子做各个
方面的辅导，为培养下一代英明的君主而努力。这会太子和先生都不在
殿内，只有几个宫女在轻轻的擦拭打扫。
LONG);

  set("exits", ([ 
 "north":__DIR__"guangtiandian",
 "south":__DIR__"xiandedian",
         ]));
  
  
  set("valid_startroom", 1);
  setup();
 
}

