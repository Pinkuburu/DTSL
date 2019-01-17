
#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

string *name=({HIC"寒月"NOR,HIR"风烟"NOR,HIW"紫魂"NOR,HIY"冷狼"NOR});

void create()
{
	int i;
	i=random(sizeof(name));
	
	set_name(name[i], ({ "spear" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","这是一把武林中至宝兵器。\n");
		set("value", 100000);
		//set("super",9);		
		set("material", "steel");
		set("weapon_prop/dodge",10);
		set("weapon_prop/spear",5);
		
	}
	init_spear(200,300,300);

	set("wield_msg", "$N「唰」地一声抽$n，只见一道寒光扑面而来。\n"NOR);
	set("unwield_msg", "$N将手中的$n插回了背后。\n");


	setup();
}


int wield()
{
    object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::wield()) return ::wield();
    
    if(owner->query("combat_exp")<500000)
    return notify_fail("你目前无法装备这件物品。\n");
    
    owner->add("max_force",5);
    owner->add("max_kee",40);
    
    
    
    return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_force",-5);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
   
   owner->add("max_kee",-40);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
   
   
    return 1;
}
