
#include <ansi.h>
inherit ROOM;

int do_push(string arg);
void create ()
{
  set ("short","山洞");
  set ("long", @LONG
这是一个小山洞，虽然外面冰天雪地，但这里却温暖如春。只见这
里的墙上挂着三枚铜牌，写着“痴”、“嗔”，“贪”三个字。不知道
推一下铜牌会有什么事情发生。
LONG);

  set("exits", ([ 
 "east":__DIR__"mishi1",
        ]));
  set("no_fight",1);
  set("no_rideto",1);
set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_push","push");
}

void clear_exit()
{
  delete("exits");
  set("exits/east",__DIR__"mishi1");
  delete("no_push");
  return;
}

void clear_ob(object ob)
{
  ob->delete_temp("push_pai1");
  ob->delete_temp("push_pai2");
  ob->delete_temp("push_pai3");
  return;
}

void noway(object ob)
{
  tell_object(ob,"你突然发现四周景物错乱，已经找不到出去的路了！！\n");
   set("exits/west",__DIR__"mishi2");
   set("exits/east",__DIR__"mishi2");
   set("exits/south",__DIR__"mishi2");
   set("exits/north",__DIR__"mishi2");
   set("no_push",1);
   clear_ob(ob);
   call_out("clear_exit",30);
   return;
}

int do_push(string arg)
{
  object ob;
  int kar;
  ob=this_player();
  if(ob->query("family_lingwu")!="jingzhai"){
   noway(ob);
   return 1;}
  
  if(ob->query("super_force_chjz_no_push")&&
     ob->query("family_lingwu")=="jingzhai"){
  	message_vision("$N推开铜牌，进入了密室。\n",ob);
  	ob->move(__DIR__"jingzhai");
        return 1;
  }
  
  if(!arg||(arg!="痴"&&arg!="嗔"&&arg!="贪"))
  return notify_fail("你要推哪块牌子？？\n");
  
  if(query("no_push"))
  return notify_fail("这里方向错乱，无法推牌子！\n");
  
  message_vision("$N推了一下"+arg+"牌!\n",ob);
  if(!ob->query_temp("push_pai1")){
   ob->set_temp("push_pai1",arg);
   return 1;}
  else
  if(!ob->query_temp("push_pai2")){
   ob->set_temp("push_pai2",arg);
   return 1;}
  else
  if(!ob->query_temp("push_pai3"))
   ob->set_temp("push_pai3",arg);
  kar=ob->query("kar");
  
  if(kar<=24){
   if(ob->query_temp("push_pai1")!="贪"||
      ob->query_temp("push_pai2")!="痴"||
      ob->query_temp("push_pai3")!="嗔"){
      	noway(ob);return 1;}
  }
  else
  if(kar<=25){
   if(ob->query_temp("push_pai1")!="嗔"||
      ob->query_temp("push_pai2")!="痴"||
      ob->query_temp("push_pai3")!="贪"){
      	noway(ob);return 1;}
  }
  else    	
  if(kar<=26){
   if(ob->query_temp("push_pai1")!="痴"||
      ob->query_temp("push_pai2")!="贪"||
      ob->query_temp("push_pai3")!="嗔"){
      	noway(ob);return 1;}
  }
  else
  if(kar<=27){
   if(ob->query_temp("push_pai1")!="嗔"||
      ob->query_temp("push_pai2")!="贪"||
      ob->query_temp("push_pai3")!="痴"){
      	noway(ob);return 1;}
  }
  else{
   if(ob->query_temp("push_pai1")!="贪"||
      ob->query_temp("push_pai2")!="嗔"||
      ob->query_temp("push_pai3")!="痴"){
      	noway(ob);return 1;} 
  }
   clear_ob(ob);
   tell_object(ob,"只听嘎吱声中，墙边露出一个暗门！\n");
   ob->set("super_force_chjz_no_push",1);
   set("exits/enter",__DIR__"jingzhai");
   call_out("clear_exit",5);
   return 1;
}   	
  
