
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

int query_autoload()
{
	return 1;
}

void create()
{
   set_name(HIY"龙鳞"NOR, ({ "long lin","armor"}) );
   set_weight(9000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "玄铁");
     set("unit", "件");
     set("value",400);
     set("long","这是武林中的至宝铠甲，名为「龙鳞之铠」。\n");
     set("armor_prop/armor", 300);
     set("armor_prop/parry", 60);
     set("armor_prop/dodge", 100);
     
   }
   setup();
}

int wear()
{
   object owner;
   
   if(!(owner = environment())->is_character()) return 0;
   
   if(!::wear()) return ::wear();
   
   if(owner->query("combat_exp")<3000000)
    return notify_fail("你目前无法装备这件物品。\n");
   owner->add("max_kee",1500);
   
   
   return 1;
}

int unequip()
{
   object owner;
    
    if(!environment()) return 0;
    if( !(owner = environment())->is_character() ) return 0;
    
    if(!::unequip()) return ::unequip();
    owner->add("max_kee",-1500);
    if(owner->query("eff_kee")>owner->query("max_kee")){
      owner->set("eff_kee",owner->query("max_kee"));
      owner->set("kee",owner->query("max_kee"));}
    
    
    return 1;
}