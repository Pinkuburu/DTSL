
inherit NPC;
string *name=({"林","山","清云","君仪"});

void create_name(object ob)
{
   ob->set_name("傅"+name[random(sizeof(name))],({ "jian ke","jian","ke","fu" }) );
   ob->set("gender", "女性" );
   ob->set("tilte","剑客");
   ob->set("long", "这是慈航静斋的白衣剑客.\n");
   return;
}

void create()
{
   set_name("傅"+name[random(sizeof(name))],({ "jian ke","jian","ke","fu" }) );
        set("gender", "女性" );
		set("tilte","剑客");
        set("age", 22);
   set("long", "这是慈航静斋的白衣剑客.\n");
       
   set("combat_exp",50000);
   set("str", 25);
   set("per", 25);
   set("attitude", "peaceful");
   set_skill("unarmed",60);
   set_skill("dodge",60);
   set_skill("parry",60);
   set_skill("force",60);
   set_skill("sword",60);
  set("gin",300);
   set("eff_gin",300);
   set("kee",300);
   set("eff_kee",300);
   set("sen",300);
   set("eff_sen",300);
   set("force",300);
   set("max_force",300);
   create_family("慈航静斋",7,"弟子");
   setup();
   carry_object(__DIR__"shayi")->wear();  
}
 int kill_object(object killer,object victim)
{
 if(killer->query("target_id")==victim->query("id"))
{
 message_vision("$N一声冷笑：这种邪魔外道，多死几个也是活该！\n",killer);
 victim->delete_temp("zhu_sx");
 return 1;
}
return 1;
}
