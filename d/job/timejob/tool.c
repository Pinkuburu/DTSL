
#include <weapon.h>
inherit STAFF;
int do_pao();
void create()
{
	set_name("锄头", ({ "chu tou", "chu","tou" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一个锄头。\n");
		set("no_drop",1);
		set("no_get",1);
		set("value",0);
		set("no_save",1);
		set("material", "steel");
		set("wield_msg", "$N拿起$n握在手中。\n");
		set("unwield_msg", "$N放下了手中的$n。\n");
	}
	init_staff(20,250,250);
	setup();
}
void init()
{
  add_action("do_pao","pao");
}
int do_pao()
{
  object ob,thing;mapping *jobs;  
  object jobctrl;
  int j;
  
  string here;int i;
  ob=this_player();
  if(environment(this_object())!=ob)
  return notify_fail("什么？\n");
  if(ob->query("sen")<50)
  return notify_fail("你的精神太差了！\n");
  ob->add("sen",-50);
  jobctrl=load_object(__DIR__"jobctrl.c");
  jobs=jobctrl->get_jobs();
  if(!sizeof(jobs)||query("no_use"))
  return notify_fail("你抡起锄头刨了半天，什么也没刨到！\n");
  here=base_name(environment(ob))+".c";
  for(i=0;i<sizeof(jobs);i++){
    if(jobs[i]["local"]==here&&jobs[i]["over"]!=1){
    	thing=new(__DIR__"thing");
    	thing->set("owner",ob);
        thing->move(environment(ob));
        message_vision("$N突然觉得好象挖到了什么东西，连忙停了下来！\n",ob);
        set("no_use",1);
        jobctrl->add_tasks(1);
        jobs[i]["over"]=1;
        jobctrl->set_jobs(jobs);
        break;}
   }
  if(i<sizeof(jobs)){
   tell_object(ob,"只听“乓”地一声，锄头被崩飞了！\n");
   if(query("equipped"))
      unequip();
   ob->delete_temp("random_job");
   ob->delete_temp("dtsl_job");
   destruct(this_object());
   return 1;}
  return notify_fail("你抡起锄头刨了半天，什么也没刨到！\n");
}
 int is_get_of(object me,object ob)
{
 if(query("owner")!=me)
 return notify_fail("那不是你的锄头！\n");
 return 1;
}
