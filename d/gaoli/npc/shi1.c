// 大唐双龙传
//shi1.c 小兵
 
inherit NPC;

void create()
{
        set_name("武士", ({ "wu shi", "wushi", "shi" }));
        set("age", 18+random(10));
        set("gender", "男性");
        set("long","这是一名供奉于高丽宫廷的武士，穿着一身武士装，威风凛凛\n");
        set("attitude", "peaceful");
   set("str", 20);
        set("combat_exp", 350000);
   set("max_kee", 1400);
   set("max_mana", 1200);
   set("max_sen", 1400);
   set("max_force", 1200);
   set("force", 1200);
   set("force_factor", 100);
        set_skill("unarmed", 140);
        set_skill("dodge", 140);
        set_skill("parry", 140);
        set_skill("blade", 140);
        set_skill("force", 140);

        setup();
        carry_object("/d/gaoli/obj/gangdao")->wield();
        carry_object("/d/gaoli/obj/armor")->wear();
}
