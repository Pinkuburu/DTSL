
inherit NPC;
#include <ansi.h>

void create()
{
   
   set_name("木人",({ "mu ren","ren"}) );
   set("gender", "男性" );
    set("combat_exp",1000000);
 
    set_skill("whip",200);
    set_skill("dodge",200);
    set_skill("parry",200);
    set_skill("force",200);
    set_skill("literate",200);
    set_skill("tianmo-jue",200);
    set_skill("tianmo-dafa",200);
    set_skill("tianmo-huanzong",200);
    set_skill("tianmo-dai",200);

    set("max_gin",3000);
    set("max_sen",3000);
    set("max_kee",3000);
    set("max_force",3000);
    set("force",3000);
 
   setup();
  
   carry_object("/d/yinkui/obj/whip")->wield();
  
  
}


int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_zhu")){
    destruct(this_object());
    return 1;
   }
   tell_object(killer,HIR"只听喀嚓一声，木人爆炸开来！\n"NOR);
   tell_object(killer,"一股巨大力量将你炸到了一个屋子内！\n"); 
   message("vision",HIR"【阴癸派】:"+killer->name()+HIR+"成为了阴癸尊者，看来江湖又少不了腥风血雨了！\n"NOR,users());
   killer->set("family_lingwu","yingui");
   killer->set("title","阴癸尊者");
   killer->reward_family_point();
   killer->move("/d/clone/room/lingwu/yingui/mishi");
   destruct(this_object());
   return 1;
}
