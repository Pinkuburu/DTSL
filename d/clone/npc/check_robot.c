
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("模糊的人影",({ "man"}) );
        set("gender", "男性" );
        set("age", 32);
    set("long","这是检查机器人的NPC。\n");
    setup(); 
}
void reset()
{
  object *usr;int i,j,m;
  object ob;object *wusr;
  ob=this_object();
  usr=users();
  m=sizeof(usr);
  j=0;
  for(;;){
   j++;
  if(j>m) break;
  i=random(sizeof(usr));
  if(!interactive(usr[i])) continue;
  if(wizardp(usr[i])) continue;
  if(usr[i]->is_busy()) continue;
  if(usr[i]->is_fighting()) continue;
  if(!living(usr[i])) continue;
  if(usr[i]->query("combat_exp")<500000) continue;
  break;}
  if(j>m) return;
  wusr=filter_array(users(),"filter_user",this_object());
  message("vision",HIR"【检查系统】:"+HIG+usr[i]->name()+HIR+"正在接受检查。\n"NOR,wusr);
  usr[i]->start_busy(2);
  tell_object(usr[i],CYN"突然一个模糊的人影朝你扑来！\n"NOR);
  COMBAT_D->do_attack(ob,usr[i],0,0,1);
  COMBAT_D->do_attack(ob,usr[i],0,0,1);
  COMBAT_D->do_attack(ob,usr[i],0,0,1);
  return;
}

int filter_user(object ob)
{
  if(wizardp(ob)) return 1;
  return 0;
}