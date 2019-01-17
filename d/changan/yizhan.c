
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","驿站");
  set ("long", @LONG
这里是长安的驿站，长安城内的信件邮寄都是通过这里来完成的。
由于长安城内的人口众多，所以驿站内的人都在不停的忙碌着，很少有
时间停下来与你打招呼。旁边的马棚里面有很多良驹，因为连日的不停
奔跑都显得相当疲倦。
LONG);

  set("exits", ([ 
 "east":__DIR__"csdajie3",
       ]));
  set("objects",([
   __DIR__"npc/bing":1,
   "/d/clone/npc/chuzi":1,
   ]));
  
  set("resource/water",1);
  set("sleep_room",1);

  set("valid_startroom", 1);
  setup();
 
}

