
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short","村西");
  set ("long", @LONG
这里是一个海边小渔村的西边，再往东边走就是小渔村内部了。据
说这个小渔村是江南海沙帮的驻地。村口站着几个大汉，相貌凶恶，打
量着来往的行人。
LONG);

  set("exits", ([ 

  "west":"/d/dongming/chaguan",
  "east":__DIR__"xiaolu1",
       ]));
  set("objects",([
	  __DIR__"npc/dahan":2,
	  ]));
set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
"/obj/board/haisha_b.c"->foo();
 
}

void init()
{
  object ob;
  
  ob=previous_object();
  if(!ob||!living(ob)) return;
  
  if(!ob->query_temp("bai_dongming/action2"))
  return;
  
  call_out("show_msg",5,ob);
}

void show_msg(object ob)
{
  if(!ob||
  environment(ob)!=this_object())
  return;
  
  ob->delete_temp("bai_dongming/action2");
  ob->set_temp("bai_dongming/action3",1);
  tell_object(ob,"\n\n你隐约听到有人商量着海沙帮要偷袭东溟派的船队！\n\n");
  return;
}