
inherit ITEM;
#include <ansi.h>
#include <org.h>
string *choice=({"blue1","red1","blue2","red2","blue3","red3"});
int do_choice(string arg);
int do_declare();
int do_list();
string list;
void create()
{
   set_name(HIY"抽签箱"NOR,({ "box"}) );  	
   set("long", "这是帮会比武大会抽签用的箱子。\n"+
               "你可以使用 list 来查看当前的赛\n"+
               "程安排。\n");
   set_weight(10);       
   set("unit","个");
   set("value",100000000);
   setup();
 
}

int is_get_of(object pal,object ob)
{
  return notify_fail("这个东西不能拿起来。\n");
}
void init()
{
   add_action("do_choice","chouqian");
   add_action("do_declare","declare");
   add_action("do_list","list");
   
}

string convert(string arg)
{
   switch(arg){
   case "blue1": return HIB"蓝色"NOR;
   case "blue2": return HIB"蓝色"NOR;
   case "blue3": return HIB"蓝色"NOR;
   case "red1":  return HIR"红色"NOR;
   case "red2":  return HIR"红色"NOR;
   case "red3":  return HIR"红色"NOR;
   default: return "error";}
}

int do_choice(string arg)
{
  object me,ob;
  int i;
  string result;
  
  me=this_player();
  
  if(!wizardp(me)&&me->query_temp("have_no_choice"))
  return notify_fail("你已经抽过签了。\n");
  if(sizeof(choice)==0)
  return notify_fail("里面已经没有任何标签了。\n");
  i=random(sizeof(choice));
  result=choice[i];
  set(choice[i],ORG_D->get_shili(me));
  choice=choice-({result});
  result=convert(result);
  if(result=="error")
  return notify_fail("出现错误，请报告给巫师。\n");
  me->set_temp("have_no_choice",result);
  tell_object(me,"你抽到了一个"+result+"小球！\n");
  message("vision",HIG"【比武大会】："+me->name()+HIG+"代表"+HIR+ORG_D->get_shili(me)+HIG+"抽到了一个"+result+HIG+"的小球！\n"NOR,users());
  return 1;
}

int do_game_list()
{
   string *team;
   int i,j,k;
  
  list="\n";
   for(i=1;i<=3;i++)
    if(query("blue"+i))
    add_array("the_first_team",query("blue"+i));
   
   for(i=1;i<=3;i++)
     if(query("red"+i))
    add_array("the_second_team",query("red"+i));
   
   if(sizeof(query("the_first_team"))==0||
      sizeof(query("the_second_team"))==0)
   return notify_fail("目前没有进行抽签或抽签还没有结束。\n");
  for(k=0;k<2;k++){
   if(k==0){
   team=query("the_first_team");
   list="\n第一小组\n";}
   else{
    team=query("the_second_team");
    list+="\n第二小组\n";}
   for(i=0;i<3;i++)     
    for(j=0;j<3;j++){
      if(team[i]==team[j]) continue;
        list+=sprintf("%30s",team[i]+" VS "+team[j]+"\n");} }
  return 1;
}

int do_declare()
{
   object ob;
  
   ob=this_player();
   
   if(!wizardp(ob))
   return 0;
  if(!do_game_list())
   return do_game_list();
  message("system",YEL"【比武赛程】："+list+"\n"NOR,users());
  return 1;
} 

int do_list()
{
   
   object ob;
 
   ob=this_player();
  if(!do_game_list())
   return do_game_list();
  list=YEL"【比武赛程】："+list+"\n"NOR;
  ob->start_more(list);
  return 1;
}


int clean_up()
{
   return 0;
}
      