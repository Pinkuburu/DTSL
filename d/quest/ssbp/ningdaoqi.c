
inherit NPC;
#include <ansi.h>

void create()
{
        
        set_name("宁道奇",({ "ning daoqi","ning","daoqi"}) );
        set("gender", "男性" );
        set("age", 52);
        set("str",30);
        set("nickname","散人");
        set("long","他看起来有些道骨仙风的样子。\n");
       set("combat_exp",6000000);
        
       set("max_kee",5000);
       set("max_sen",5000);
       set("max_gin",5000);
       set("max_force",10000);
       set("force",10000);
       set_skill("dodge",350);
       set_skill("parry",350);
       set_skill("force",350);
       set_skill("jiuxuan-dafa",350);
       set_skill("jiuying-dodge",350);
       set_skill("strike",350);
       set_skill("sanshou-strike",350);
       set("jiali",200);
       set("apply_points",250);
       set("chat_chance_combat",70);
       set("chat_msg_combat",({
       	 (:command("perform bapu"):),
       	 }));
       
    setup();
  
}

