// 大唐双龙传

//侠客。

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("侠客", ({ "xia ke", "xia", "ke" }) );
        set("gender", "男性");
        set("age", 35);
        set("long","这是一个高丽的侠客，准备到中原去闯一番天下。\n");
        set("combat_exp", 300000+random(40000));
        set("attitude", "heroism");
        set("str", 30);
        set("max_kee", 1000);
        set("max_sen", 500);
        set("max_gin", 700);
        set("force", 400);
        set("max_force", 500);
        set("force_factor", 25);
        set_skill("blade", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);

        setup();

        carry_object("/d/gaoli/obj/gangdao")->wield();
        carry_object("//d/gaoli/obj/armor")->wear();
}


