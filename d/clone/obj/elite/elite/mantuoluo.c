
#include <armor.h>
#include <ansi.h>

inherit FINGER;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIG"曼佗罗"NOR, ({ "man tuo luo","finger"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "铁");
     set("unit", "枚");
     set("value",400);
     set("long","这是佛门中的至宝扳指，名为「达摩之曼佗罗」。\n");
     set("armor_prop/armor",50);
     set("armor_prop/dodge",200);
     set("armor_prop/mantuoluo",1);
   }
   setup();
}

int wear()
{
   object owner;
   
   if(!(owner = environment())->is_character()) return 0;
   
   if(!::wear()) return ::wear();
   if(owner->query("combat_exp")<2000000)
    return notify_fail("你目前无法装备这件物品。\n");
   owner->add("max_kee",500);
   
   if(owner->query_temp("apply/mantuoluo")==5){
    	message_vision(HIY"$N"+HIY+"的身上隐隐发出一阵金色的光芒，照得四周非常明亮。\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_force",1000);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_kee",-500);
    if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    
    if(owner->query_temp("apply/mantuoluo")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_force",-1000);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}