
#include <ansi.h>
#include <job_money.h>
inherit ROOM;

int do_wa();
void create ()
{
  set ("short","山洞");
  set ("long", @LONG
这里是一个山洞。里面黑乎乎的，伸手不见五指。似乎有什么声音，
你不禁加倍小心起来。你发现地上好象有个土包，似乎埋着什么东西。
LONG);

  set("exits", ([ 

   "southwest":__DIR__"shandong3",
              ]));
 set("objects",([ "/d/clone/npc/beast/yezhu":1,]));

set("outdoors","dabashan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_wa","wa");
}

int do_wa()
{
   object me,ob,killer;object *armor;
   me=this_player();
   
   armor=children(__DIR__"npc/obj/armor");
   if(environment(me)->query("no_bao")||sizeof(armor)>2)
   return notify_fail("你挖了半天，发现什么也没有。\n");
   message_vision("$N蹲下身去，用手挖了起来。\n",me);
   environment(me)->set("no_bao",1);
   killer=new(__DIR__"npc/killer");
   killer->set_status(me);
   killer->set("name","蒙面人");
   killer->set("id","man");
   killer->set("nickname","蒙面武士");
   killer->set("title","夺宝大王");

   killer->move(environment(me));
   me->start_busy(2);
   message_vision(HIR"\n$N冷笑道：你敢和我抢宝物，有种！拿命来吧！！\n"NOR,killer);
   killer->kill_ob(me);
   return 1;
}
   
   

