
#include <armor.h>
#include <ansi.h>

inherit BOOTS;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIC"幻灵"NOR, ({ "huan ling","boots"}) );
   set_weight(800);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "铁");
     set("unit", "双");
     set("value",400);
     set("long","这是武林的至宝之物，名为「大漠之幻灵」。\n");
     set("armor_prop/dodge",70);
     set("armor_prop/dodge_skill",40);
     set("armor_prop/damo",1);
   }
   setup();
}

int wear()
{
   object owner;
   
   if(!(owner = environment())->is_character()) return 0;
   
   if(!::wear()) return ::wear();
   
   if(owner->query("combat_exp")<1000000)
    return notify_fail("你目前无法装备这件物品。\n");
   
  if(owner->query_temp("apply/damo")==5){
    	message_vision(HIY"$N"+HIY+"的身上隐隐发出阵阵狂风的声音，四周卷起一阵的风沙。\n"NOR,owner);
    	owner->add_temp("apply/damage",50);
    	owner->add("max_kee",500);
    	owner->add_temp("apply/parry",60);}
    	
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
   
    if(owner->query_temp("apply/damo")==4){
    	owner->add_temp("apply/damage",-50);
    	owner->add("max_kee",-500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
      
      owner->add_temp("apply/parry",-60);}
    
    return 1;
}