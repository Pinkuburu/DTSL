
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("官兵",({ "bing" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是杨广手下的当差的官兵。\n");
       
   set("combat_exp",200000);
   set("str", 26);
   set_skill("unarmed",120);
   set_skill("dodge",120);
   set_skill("sword",120);
   set_skill("parry",120);
   set_skill("tianmo-huanzong",120);
   set_skill("linglong-yuquan",120);
   set_skill("cuff",120);
    setup();
 
}

void die()
{
	object me,killer;
    me=this_object();
	killer=me->query_temp("last_damage_from");
	if(killer->query_temp("li_job")&&
	   query("target_id")==killer->query("id"))
	{killer->set_temp("defence_ok",1);}
	return ::die();
}

