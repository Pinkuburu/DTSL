
#include <ansi.h>
inherit ROOM;
int do_push(string arg);
void create ()
{
  set ("short",HIB"密室"NOR);
  set ("long", @LONG
这里是一间密室，看起来已经很久没有人来过了。这里放着
一张桌子，上面有个很破旧的梳妆台。旁边的墙上挂着五面铜镜
「jing」，仔细看去，上面好象有几个手印。
LONG);
 set("item_desc",([
 "jing":"这是五面铜镜，分别为红、蓝、绿、紫、白，\n"+
        "上面花纹交错，不知道推[push]一下会怎么样\n",
 ]));
 set("valid_startroom", 1);
  setup();
 
}
void init()
{
   add_action("do_push","push");
}
void clear(object ob)
{
  ob->delete_temp("push_jing");
  ob->delete_temp("huajian_quest1");
  ob->delete_temp("huajian_quest2");
  ob->delete_temp("huajian_quest3");
  return;
}
void noway(object ob)
{
  clear(ob);
  message_vision(HIR"突然$N的脚下一软，地板已经掀起来，$N掉了进去！\n"NOR,ob);
  ob->move(__DIR__"downroom");
  return;
}
int do_push(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||
  (arg!="红铜镜"&&
   arg!="蓝铜镜"&&
   arg!="绿铜镜"&&
   arg!="紫铜镜"&&
   arg!="白铜镜"))
  return notify_fail("你要推什么？\n");
  message_vision(YEL"$N的手朝"+arg+"缓缓推了过去。\n"NOR,ob);
  
  if(ob->query("super_force_huajian_nocheck")){
  	tell_object(ob,YEL"只听喀吱喀吱几声，墙边露出了一个暗门！\n你连忙走了进去。\n"NOR);
  	ob->move(__DIR__"huajian");
  	return 1;
  }	
  
  ob->add_temp("push_jing",1);
  if(!ob->query_temp("huajian_quest1"))
  ob->set_temp("huajian_quest1",arg);
  else if(!ob->query_temp("huajian_quest2"))
  ob->set_temp("huajian_quest2",arg);
  else if(!ob->query_temp("huajian_quest3"))
  ob->set_temp("huajian_quest3",arg);
  if(ob->query_temp("push_jing")<3)
  return 1;
  if(ob->query("per")==26)
    if(ob->query_temp("huajian_quest1")!="蓝铜镜"||
       ob->query_temp("huajian_quest2")!="白铜镜"||
       ob->query_temp("huajian_quest3")!="绿铜镜"){
       	noway(ob);return 1;}
  if(ob->query("per")==27)
    if(ob->query_temp("huajian_quest1")!="紫铜镜"||
       ob->query_temp("huajian_quest2")!="蓝铜镜"||
       ob->query_temp("huajian_quest3")!="红铜镜"){
       	noway(ob);return 1;}
  if(ob->query("per")==28)
    if(ob->query_temp("huajian_quest1")!="蓝铜镜"||
       ob->query_temp("huajian_quest2")!="红铜镜"||
       ob->query_temp("huajian_quest3")!="白铜镜"){
       	noway(ob);return 1;}
  if(ob->query("per")==29)
    if(ob->query_temp("huajian_quest1")!="绿铜镜"||
       ob->query_temp("huajian_quest2")!="紫铜镜"||
       ob->query_temp("huajian_quest3")!="蓝铜镜"){
       	noway(ob);return 1;}
  if(ob->query("per")==30)
    if(ob->query_temp("huajian_quest1")!="红铜镜"||
       ob->query_temp("huajian_quest2")!="白铜镜"||
       ob->query_temp("huajian_quest3")!="紫铜镜"){
       	noway(ob);return 1;}
  clear(ob);
  tell_object(ob,YEL"只听喀吱喀吱几声，墙边露出了一个暗门！\n"NOR);
  ob->set("super_force_huajian_nocheck",1);
  set("exits/enter",__DIR__"huajian");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
