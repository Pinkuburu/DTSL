
inherit NPC;

void create()
{
   set_name("尤楚红",({ "you chuhong","you","chuhong" }) );
        set("gender", "女性" );
        set("age", 72);
   set("long", "她是独孤阀的第一高手尤楚红。\n");
   set("shili","dugu");
   set("combat_exp",2600000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",220);
   set_skill("dodge",220);
   set_skill("parry",220);
   set_skill("force",220);
   set_skill("sword",220);
   set_skill("cuff",220);
   set_skill("dugu-jianfa",220);
   set_skill("youming-zhang",220);
   set_skill("staff",300);
   set_skill("pifeng-zhang",300);
   set("max_gin",3500);
   set("max_sen",3500);
   set("max_kee",4000);
   set("force",4000);
   set("max_force",4000);
   setup();
   carry_object(__DIR__"obj/cloth-f")->wear();
   carry_object(__DIR__"obj/xiuhuaxie")->wear();
   carry_object(__DIR__"obj/biyuzhang")->wield();
  
}

