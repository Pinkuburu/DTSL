
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","码头");
  set ("long", @LONG
这里是永安大渠的北门码头，很多商船停在这里上货和下货，脚夫们
前前后后忙的不亦乐乎，据说这里现在被刚刚进入长安没多久的同兴社控
制了，从而引起了关中大派－－京兆联的不满。
LONG);

  set("exits", ([ 
 "west":__DIR__"tongxingshe",
       ]));
       
  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

