
inherit NPC;

#include <ansi.h>
void create()
{
   set_name("宋玉华",({ "song yuhua","song","yuhua" }) );
        set("gender", "女性" );
       set("age", 22);
   set("long", "他就是宋家堡的宋玉华。她是解文龙的妻子。\n");
       
   set("combat_exp", 300000);
   set("str", 28);
   set("per", 27);
   set("attitude", "peaceful");
   set("gin",1000);
   set("max_gin",1000);
   set("kee",1000);
   set("max_kee",1000);
   set("sen",1000);
   set("max_sen",1000);
   set("force",1000);
   set("max_force",1000);
   set_skill("tiandao-bajue",100);
   set_skill("blade",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("cuff",100);
   set_skill("anxiang-fuying",100);
   set_skill("force",110);
   set_skill("tiangang-sanjue",100);
   set_skill("poyu-quan",100);
   create_family("宋家堡",3,"门人");
   set("shili",([
      "name":"songjia_b",
      ]));
   setup();
   carry_object(__DIR__"obj/cloth2")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}


