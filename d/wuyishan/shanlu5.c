
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。这里没有什么声音，看来很少有人来这里。南边
是一片荆棘林，荆棘茂盛，看来进去就是凶多吉少，还是不进去为好。
LONG);

  set("exits", ([ 

   "northeast":__DIR__"shanlu3",
    "southwest":__DIR__"jingjilin",
           ]));
/* set("objects",([
     __DIR__"npc/youke":2,
     ]));*/
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object ob,string dir)
{
  if(dir=="southwest"&&!userp(ob))
  	return 0;
  
  return ::valid_leave(ob,dir);

}
