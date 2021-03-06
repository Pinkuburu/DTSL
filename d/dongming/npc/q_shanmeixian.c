
inherit NPC;
#include <ansi.h>

void create()
{
   
   set_name("木人",({ "mu ren","ren"}) );
   set("gender", "男性" );
    set("combat_exp",1000000);
    set_skill("whip",200);
    set_skill("parry",200);
    set_skill("dodge",200);
    set_skill("force",200);
    set_skill("literate",200);
    set_skill("dongming-xinfa",200);
    set_skill("bihai-force",200);
    set_skill("shuiyun-xiufa",200);
    set_skill("nishang-piaoming",200);
    
    set("max_gin",3000);
    set("max_sen",3000);
    set("max_kee",3000);
    set("max_force",3000);
    set("force",3000);
  
   setup();
   
   carry_object(__DIR__"obj/whip")->wield();
  
}

int surrender(object killer,object victim)
{
   object ob;
   if(!killer->query_temp("gage_shan")){
     destruct(this_object());
     return 1;
   }
   message("vision",HIG"【东溟派】：东溟夫人纵声长啸：天下英雄听了，"+killer->name()+HIG+"已成为我派东溟战将！\n"NOR,users());
   
   tell_object(killer,"木人喀嚓一声裂成了碎片！\n");
   tell_object(killer,"木人里落出一张纸，上面写道：本派有一个修炼东溟心法的地方，\n"+
                      "据说在海边的悬崖处。但一直没有人找到，看你能不能找到，光大本派了！\n");
   killer->set("family_lingwu","dongming");
   killer->set("title","东溟战将");
   killer->reward_family_point();
   destruct(this_object());
   return 1;
}