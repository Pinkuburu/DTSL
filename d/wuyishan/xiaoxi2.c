
#include <ansi.h>
inherit ROOM;

int do_tiao(string arg);
void create ()
{
  set ("short","小溪");
  set ("long", @LONG
这里是一条小溪。看来这条小溪是流到山下了。旁边有一个破竹筏，
看来已经不能载人了，不知道跳上去会有什么后果。
LONG);

  set("exits", ([ 

   "south":__DIR__"shulin4",
 
          ]));
set("objects",([
 "/d/clone/npc/beast/yetu":2,
 ]));
set("outdoors","wuyishan");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_tiao","tiao");
}

int do_tiao(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="竹筏")
  return notify_fail("你想要往哪里跳？\n");
  if(ob->is_busy())
  return notify_fail("你正忙着呢！\n");
  if(ob->is_fighting())
  return notify_fail("你正打仗呢！\n");
  if(ob->query_skill("dodge",1)>=101)
  return notify_fail("你觉得破竹筏没什么，停了下来。\n");
  if(ob->query("sen")<25)
  return notify_fail("你刚想跳，觉得头昏眼花，停了下来。\n");
  ob->add("sen",-25);
  ob->improve_skill("dodge",ob->query_int()/2+ob->query_cor());
  if(ob->query_skill("dodge",1)<50)
  message_vision(YEL"$N猛地朝竹筏跳了过去，脚下一个不稳，摔到了水中！\n"NOR,ob);
  else if(ob->query_skill("dodge",1)<100)
  message_vision(YEL"$N猛地朝竹筏跳了过去，竹筏晃了几晃，就连忙跃回岸边！\n"NOR,ob);
  else if(ob->query_skill("dodge",1)<150)
  message_vision(YEL"$N猛地朝竹筏跳了过去，未待竹筏摇晃，已经潇洒地跃回岸边！\n"NOR,ob);
  return 1;
}
