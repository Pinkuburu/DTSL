
inherit NPC;

void create()
{
        set_name("商人", ({"shang ren","shang","ren"}));
        set("gender", "男性");
        set("age", 34);
        set("long","这是一位走南闯北的商人。\n");
        set("str", 26);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("kee", 500); 
        set("max_kee", 500);
        set("gin", 100);
        set("max_gin", 100);
        set("sen",300);
        set("max_sen",300);
		set("force",800);
		set("max_force",800);
        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("env/wimpy", 50);

        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 200);
        set_skill("cuff",120);
	set_skill("force",120);
	set_skill("wuxing-quan",130);
        set("hand",({"wuxing-quan"}));
        set_temp("apply/dodge", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 40);
        set("chat_chance",20);
        set("chat_msg",({
          "商人说道：说到“无奸不商”，我可不同意，我做生意可是很公平的！\n",
          "商人笑道：各位需要什么货物，只要和我说一声，保证给你弄到！\n",
        }));
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        add_money("silver",10);
}

