
inherit NPC;
inherit F_DEALER;
void create()
{
   set_name("金老板",({ "jin laoban","jin","laoban" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是当铺的老板。\n");
       
   set("combat_exp", 100000);
   set("str", 28);
   set("attitude", "peaceful");
   set_skill("unarmed",70);
   set_skill("parry",70);
   set_skill("dodge",70);
   set_skill("force",70);
   set("max_force",200);
   set("force",200);
   setup();
   
  
}
void init()
{
	add_action("do_buy","buy");
	add_action("do_list","list");
	add_action("do_sell","sell");
	add_action("do_value","value");
}

void die()
{
  object *inv;int i;
  inv=all_inventory(this_object());
  if(sizeof(inv)==0)
  return ::die();
  for(i=0;i<sizeof(inv);i++)
   destruct(inv[i]);
   return ::die();
}