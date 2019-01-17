
#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
	set_name(WHT"天魔斩"NOR, ({ "tianmo zhan","zhan","dagger" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("no_save",1);
		set("long", "这是一把天魔斩，专破内家真气。\n");
		set("value", 50);
		set("rumor",1);
		set("super",5);
		set("no_sell",1);
		set("material", "steel");
	}
	init_dagger(120,180,180);


	set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n藏入怀中。\n");


	setup();
}

void hit_ob(object me,object victim)
{
  if(random(5)>3&&victim->query("force")>0){
    victim->add("force",-me->query("apply_points"));
    if(victim->query("force")<0)
    victim->set("force",0);
    message_vision("\n$N的"+query("name")+"击中$n，$n的真气不由得狂泻而出！\n",
      me,victim);
  }
 return;
}