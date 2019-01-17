inherit ROOM;
#include <ansi.h>

int do_install(string arg);

void create ()
{
  set ("short","春园");
  set ("long", @LONG
这里是九江的春园，来来往往行人很多，热闹的声音不绝于耳。旁
边还有一座阁楼，门前牌匾上“春在楼”三个金漆的大字在阳光照耀下
闪闪发光。楼上传来了喝酒、嬉笑、吵骂的声音，又给春园增添了一份
热闹。
LONG);

  set("exits", ([ 

  "up":__DIR__"chunzailou",
  "west":"/d/jiujiang/beidajie2",
         ]));
set("outdoors","jiujiang");
  set("valid_startroom", 1);
  set("cisha_job",1);
  setup();
 
}

void init()
{
  add_action("do_install","install");
}

int do_install(string arg)
{
   object ob;
   object tool;
   object *t;
   int i;
   ob=this_player();
   if(!ob->query_temp("dtsl_job_cisha/step2"))
   return notify_fail("这里不准安装东西！\n");
   if(!arg)
   return notify_fail("你要安装什么？\n");
   if(!objectp(tool=present(arg,ob)))
   return notify_fail("你身上没有这个东西。\n");
   if(!tool->query("cisha_job"))
   return notify_fail("这个东西不能在这里安装。\n");
   message_vision("$N拿着鱼钩挂到了旁边的树上，同时用力一甩，把\n"+
        "另一边甩挂到了旁边的春在楼上！\n",ob);
   tell_room(__DIR__"chunzailou","楼下一个人甩上来一条鱼线，绕着柱子转了几转，鱼钩最后紧紧嵌到了柱子中！\n");
   t=ob->query_team();
   if(sizeof(t)>0){
    for(i=0;i<sizeof(t);i++)
     if(t[i]&&environment(t[i])==environment(ob)&&living(t[i]))
       message_vision(YEL"$N双手一抻鱼线，身形一晃，纵到了旁边的春在楼中！\n"NOR,t[i]);}
   else message_vision(YEL"$N双手一抻鱼线，身形一晃，纵到了旁边的春在楼中！\n"NOR,ob);
   if(sizeof(t)<=0)
   tell_room(__DIR__"chunzailou","楼下一个人影蹭地一声蹿了上来！\n");
   else
   tell_room(__DIR__"chunzailou","楼下几个人影蹭地一声蹿了上来！\n");
   destruct(tool);
   if(sizeof(t)>0){
    for(i=0;i<sizeof(t);i++)
     if(t[i]&&living(t[i])){
     if(t[i]->query_temp("dtsl_job_cisha/step2"))
     t[i]->set_temp("dtsl_job_cisha/step3",1);
     t[i]->set_temp("dtsl_job_cisha/can_flee",1);
     t[i]->move(__DIR__"chunzailou");}}
   else{
   ob->set_temp("dtsl_job_cisha/can_flee",1);
   ob->move(__DIR__"chunzailou");
   ob->set_temp("dtsl_job_cisha/step3",1);}
   ob->apply_condition("cisha_job",1);
   return 1;
}
   
int valid_leave(object ob,string dir)
{
  object *target;
  int i;
  target=all_inventory(environment(ob));
  for(i=0;i<sizeof(target);i++)
   if(target[i]->query("target_id")==ob->query("id"))
    return notify_fail(target[i]->name()+"一把拉住了你！\n");
  return ::valid_leave(ob,dir);
}
