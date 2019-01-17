#include <ansi.h>

inherit NPC;

void create()
{
        set_name("保镖", ({"guard"}));
        set("long", "这是一个保镖。\n");
        set("attitude", "peaceful");

        set("max_gin", 800);
        set("max_kee", 800);
        set("max_sen", 800);
        set("force", 500);
        set("max_force", 500);
        set("combat_exp", 500000);
        set_skill("unarmed",130);
        set_skill("parry",130);
        set_skill("dodge",130);
        set_skill("cuff",130);
       setup();
}

int kill_object(object killer,object victim)
{
  message_vision(HIR"$N一声长笑，身行一晃，踪迹不见！\n"NOR,killer);
  destruct(killer);
  return 1;
}
