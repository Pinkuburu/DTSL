
#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIC"长须"NOR, ({ "chang xu","whip" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 400);
               // set("super",9);
                set("long","这是武林的至宝，名为「蛟龙之长须」。\n");
                set("material", "skin");
                set("weapon_prop/parry",40);
                set("weapon_prop/jiaolong",1);
        }
        init_whip(200,300,300);

        set("wield_msg", HIC"$N"+HIC+"从腰间摸出一条$n"+HIC+"握在手中，瞬时四周打了道闪电！\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");

        setup();
}

int wield()
{
    object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::wield()) return ::wield();
    
    if(owner->query("combat_exp")<3000000)
    return notify_fail("你目前无法装备这件物品。\n");
    
    owner->add("max_force",500);
    owner->add("max_kee",100);
    
    if(owner->query_temp("apply/jiaolong")==5){
    	message_vision(HIC"$N"+HIC+"的身上发出龙吟般的声音，久久不绝。\n"NOR,owner);
    	owner->add_temp("apply/damage",100);
    	owner->add("max_kee",500);
    	owner->add("max_force",2000);}
    
    return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_force",-500);
    if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));
    owner->add("max_kee",-100);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    
    if(owner->query_temp("apply/jiaolong")==4){
    	owner->add_temp("apply/damage",-100);
    	owner->add("max_kee",-500);
    	if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    	owner->add("max_force",-2000);
    	if(owner->query("force")>owner->query("max_force"))
      owner->set("force",owner->query("max_force"));}
    
    return 1;
}


