
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"书房"NOR);
  set ("long", @LONG
这里是王世充的书房，他平时在这里办公。有几名侍卫守护在书房
门口，一看就知道江湖中的武林高手。这里放了很多书籍，虽然王世充
非一等帅才，但来洛阳投奔他的豪侠也是不少。
LONG);

  set("exits", ([ 

  "south":__DIR__"zoulang1",
      ]));
  set("objects",([
	  __DIR__"npc/wangshi-chong":1,
	  ]));
  set("victory","luoyang");

  
  set("valid_startroom", 1);
  setup();
 
}



