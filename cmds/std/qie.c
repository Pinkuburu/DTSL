// qie . yanyan.2000.

#include <ansi.h>;
inherit F_CLEAN_UP;
inherit F_COMMAND;
inherit F_DBASE;

int main(object me, string arg)
{
     object weapon,shouji,corpse;
	 if(!arg)
		return notify_fail("你要切什么?\n");
	if(!objectp(corpse=present(arg, environment(me))))
	return notify_fail("这里没有这个东西！\n");
	if(!corpse->is_corpse())
	return notify_fail("这个东西不是尸体，不能切！\n");
	if(corpse->query("no_head"))
	return notify_fail("这已经是无头的尸体了!\n");
	if(!objectp(weapon=me->query_temp("weapon")))
	return notify_fail("你用什么切?\n");
	
if((string)weapon->query("skill_type")=="sword"||(string)weapon->query("skill_type")=="blade"
 ||(string)weapon->query("skill_type")=="dagger"
 ||(string)weapon->query("skill_type")=="axe") 
  {  
	  shouji=new("/obj/shouji");  
	  shouji->set("dead_id",(string)corpse->query("dead_id"));
          shouji->set("killed_by",(string)corpse->query("killed_by")); 
	  shouji->set("long","这是"+corpse->name()+"的首级\n");
	  corpse->set("name","无头尸体");	 
	  corpse->set("long","这是一具尸体，但以分辨不出他是谁了\n");
	  corpse->set("no_head",1);
	  shouji->move(me);			
	message_vision(HIR"只听‘噗’地一声，$N切下了尸体的首级，溅起一片血光！\n"NOR,me);  
return 1;} 
      else return notify_fail("这个东西不能用来切尸体!\n");
	  

}