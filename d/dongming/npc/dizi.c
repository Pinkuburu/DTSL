
inherit NPC;
#include <ansi.h>
void create()
{
   set_name("女弟子",({ "nv dizi","nv","dizi" }) );
        set("gender", "女性" );
	  set("age", 20);
   set("long", "这是东溟派的学艺弟子。\n");
       
   set("combat_exp",80000);
   set("str", 23);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",70);
   set_skill("dodge",70);
   set_skill("parry",70);
   set_skill("force",70);
   set_skill("sword",70);
   set_skill("strike",70);
   set_skill("dongming-xinfa",70);
  
   set_skill("shuiyun-xiufa",70);

   set_skill("nishang-piaoming",70);
  
   set("max_gin",500);
   set("max_sen",500);
   set("max_kee",500);
   set("force",500);
   set("max_force",500);
   create_family("东溟派",7,"弟子");
   setup();
   carry_object(__DIR__"obj/caiyi")->wear();
   carry_object(__DIR__"obj/changjian")->wield();
  
}
