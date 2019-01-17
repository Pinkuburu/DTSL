inherit F_MASTER;
inherit NPC;

void create()
{
        set_name("学院老师", ({"lao shi", "lao","shi"}));
        set("gender", "男性");
        set("age", 34);
        set("long","这是学院的老师，已经获得了硕士学位！\n");
        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);

        set("kee", 500); 
        set("max_kee", 500);
        set("gin", 100);
        set("max_gin", 100);
        set("sen",300);
        set("max_sen",300);
        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("env/wimpy", 50);

        set_skill("literate",10);
        set_skill("force",10);
        set_skill("parry",10);
        set_skill("dodge",10);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);
        create_family("学院派",5,"硕士");
        setup();
      
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	
        return 1;
}

int prevent_learn(object ob,string skill)
{
  return 1;
  
}


void attempt_apprentice(object ob)
{   
	
	command("say 咱们只是在这里示范一下，不算数的。\n");
	command("say 我也还会点技能，你要是不闲气，就学着试试看吧！\n");
	return;
}