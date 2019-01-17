inherit ROOM;
#include <ansi.h>
int do_kick(string arg);
int do_insert(string arg);

void create()
{
	set("short",HIG"天井"NOR);
	set("long", @LONG
这里是扬州书院的后院。前院传来了学生朗朗的读书声。旁边有一
个小屋，房门关的很紧密。
LONG);
        set("exits",([
          "south":"/d/yangzhou/shuyuan",
          ]));
	setup();      
}
void init()
{
  add_action("do_kick","kick");
  add_action("do_insert","insert");
} 

int do_kick(string arg)
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_csj/step5"))
  return 0;
  if(!arg||arg!="door")
  return notify_fail("你要踢什么？\n");
  message_vision(HIR"$N照着房门踹了一脚，只听“碰”地一声，房门应声而开！\n"NOR,ob);
  ob->delete_temp("dtsl_quest_csj/step5");
  ob->set_temp("dtsl_quest_csj/step6",1);
  set("exits/enter",__DIR__"shufang");
  call_out("del_exit",5);
  return 1;
}


int do_insert(string arg)
{
  object ob;
  object obj;
  ob=this_player();
  if( !objectp(obj = present("yaoshi", ob)) )
      return notify_fail("什么?\n");
  message_vision(HIR"$N把钥匙插进锁眼。\n"NOR,ob);
  return 1;
}

void del_exit()
{
  delete("exits/enter");
  return;
}
   
  
