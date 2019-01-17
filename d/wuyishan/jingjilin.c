
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIR"荆棘林"NOR);
  set ("long", @LONG
你走到了荆棘林中！这里荆棘茂盛，每走一步都有很大的危险，看
来你要小心了。
LONG);

  set("exits", ([ 

   "northeast":__DIR__"shanlu5",
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
  if(userp(ob)&&dir=="northeast"&&ob->query_skill("dodge",1)<100)
  {
     message_vision(HIR"$N刚想迈步，被荆棘刮了一下！\n"NOR,ob);
     ob->receive_wound("kee",600);
     return notify_fail("你疼地走不动了！\n");
     
  }
  message_vision("$N奋力一越，但还是被荆棘刮了一下！\n",ob);
  ob->receive_wound("kee",400);
  return ::valid_leave(ob,dir);
}