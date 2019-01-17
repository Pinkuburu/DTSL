inherit ROOM;
#include <ansi.h>
int do_ci(string arg);
void create()
{
	set("short",HIB"棋室"NOR);
	set("long", @LONG
这是弈剑派的棋室。不过这里看来灰尘很多，已经很久没有
人来这里了。旁边的墙上挂着一幅棋谱，上面已经是残局了，只
是还没有下完，不知道是哪两位前辈高人下的棋。或许你能从棋
谱「qipu」中找出什么秘密来。
LONG);
  set("item_desc",([
   "qipu":"看到棋谱上的棋子,令人联想起剑法来,禁不住想用剑刺那些黑白棋子\n",
   ]));
	setup();      
}
void init()
{
  add_action("do_ci","ci");
}
void clear(object ob)
{
  ob->delete_temp("ci_times");
  ob->delete_temp("yjp_quest1");
  ob->delete_temp("yjp_quest2");
  ob->delete_temp("yjp_quest3");
  return;
}
void noway(object ob)
{
  clear(ob);
  message_vision(MAG"只听啪地一声,棋盘上飞起一枚棋子,力道奇大,正好砸到你的头部!\n"NOR,ob);
  ob->unconcious();
  return;
}
int do_ci(string arg)
{
  object ob,weapon;
  ob=this_player();
  
  if(!arg||
  (arg!="黑棋"&&arg!="白棋"))
  return notify_fail("你想刺什么?\n");
  if(!ob->query_temp("weapon"))
   return notify_fail("你疯狂地用手抓了起来!!\n");
  weapon=ob->query_temp("weapon");
  if(weapon->query("skill_type")!="sword")
  return notify_fail("你发现"+weapon->name()+"在这里毫无用处!\n");
  
  if(ob->query("super_force_yjp_no_ci")&&
     ob->query("family_lingwu")=="yjp"){
     message_vision("$N一刺棋子，棋盘喀嚓一声，翻了过来！$N闪身进入了密室！\n",ob);
     ob->move(__DIR__"yjp");
     return 1;
  }
  
  ob->add_temp("ci_times",1);
  if(!ob->query_temp("yjp_quest1"))
  ob->set_temp("yjp_quest1",arg);
  else if(!ob->query_temp("yjp_quest2"))
  ob->set_temp("yjp_quest2",arg);
  else if(!ob->query_temp("yjp_quest3"))
  ob->set_temp("yjp_quest3",arg);
  message_vision(YEL"$N朝"+arg+"刺了一下!\n"NOR,ob);
  if(ob->query_temp("ci_times")<3)
  return 1;
  if(ob->query_int()<=35){
    if(ob->query_temp("yjp_quest1")!="黑棋"||
       ob->query_temp("yjp_quest2")!="白棋"||
       ob->query_temp("yjp_quest3")!="白棋"){
       	noway(ob);return 1;}}
  else
  if(ob->query_int()<=40){
    if(ob->query_temp("yjp_quest1")!="白棋"||
       ob->query_temp("yjp_quest2")!="白棋"||
       ob->query_temp("yjp_quest3")!="白棋"){
       	noway(ob);return 1;}}
  else
  if(ob->query_int()<=45){
    if(ob->query_temp("yjp_quest1")!="白棋"||
       ob->query_temp("yjp_quest2")!="黑棋"||
       ob->query_temp("yjp_quest3")!="白棋"){
       	noway(ob);return 1;}}
  else
  if(ob->query_int()<=50){
    if(ob->query_temp("yjp_quest1")!="白棋"||
       ob->query_temp("yjp_quest2")!="白棋"||
       ob->query_temp("yjp_quest3")!="黑棋"){
       	noway(ob);return 1;}}
  else
  if(ob->query_int()<=55){
    if(ob->query_temp("yjp_quest1")!="黑棋"||
       ob->query_temp("yjp_quest2")!="白棋"||
       ob->query_temp("yjp_quest1")!="黑棋"){
       	noway(ob);return 1;}}
  else
  if(ob->query_int()<=60){
    if(ob->query_temp("yjp_quest1")!="黑棋"||
       ob->query_temp("yjp_quest2")!="黑棋"||
       ob->query_temp("yjp_quest3")!="白棋"){
       	noway(ob);return 1;}}
  clear(ob);
  message_vision(YEL"$N只听棋盘喀嚓一声,翻了过来,后面露出了一个暗门!\n"NOR,ob);
  ob->set("super_force_yjp_no_ci",1);
  set("exits/enter",__DIR__"yjp");
  call_out("del_enter",5);
  return 1;
}
void del_enter()
{
  delete("exits/enter");
  remove_call_out("del_enter");
}
