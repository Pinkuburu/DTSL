
inherit ROOM;
#include <ansi.h>
void create()	
{
	set("short","厨房");
	set("long", @LONG
这是一间小厨房，虽然不大，但是锅碗瓢盆，油盐酱醋，到
很奇全。灶台上堆满了新鲜瓜果蔬菜，活鱼活虾，不仅不脏不乱，
还十分干净整齐。
LONG);
    set("exits", ([
	        "south":__DIR__"shanzhuang",
	      
 	]));
      set("no_fight",1);
      setup();
      replace_program(ROOM);
	
}
