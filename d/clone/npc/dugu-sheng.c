
inherit NPC;

void create()
{
   set_name("独孤盛",({ "dugu sheng","dugu","sheng" }) );
        set("gender", "男性" );
        set("age", 32);
        set("tetle","侍卫统领");
   set("long", "他是独孤阀的高手独孤盛，是隋朝的大内侍卫统领。\n");
   set("shili","dugu");
   set("combat_exp",600000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",160);
   set_skill("dodge",160);
   set_skill("parry",160);
   set_skill("force",160);
   set_skill("sword",160);
   set_skill("cuff",160);
   set_skill("dugu-jianfa",160);
   set_skill("youming-zhang",160);
   set("max_gin",1500);
   set("max_sen",1500);
   set("max_kee",2000);
   set("force",2000);
   set("max_force",2000);
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/guanxue")->wear();
   carry_object(__DIR__"obj/sword")->wield();
}

