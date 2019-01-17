
inherit NPC;
string *name1=({"单"});
string *name2=({"萍","绣风","丽","秋菊","雪","梅","芬","雅"});
void create()
{
   set_name(name1[random(sizeof(name1))]+name2[random(sizeof(name2))]
   ,({ "killer" }) );
        set("gender", "女性" );
        set("title","宋家堡的叛徒");
        set("age", 32);
   set("long", "这是宋家堡的叛徒。\n");
   set("combat_exp", 800000);
   set("str", 30);
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",3000);
   set("force",3000);
   set_skill("force",200);
   set_skill("tiangang-sanjue",200);
   set_skill("tiandao-bajue",200);
   set_skill("blade",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("anxiang-fuying",200);
   set("dodge",({"anxiang-fuying"}));
   set("blade",({"tiandao-bajue"}));
   set("force_skill",({"tiangang-sanjue"}));
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
   	(:perform_action,"bajue":),
   	}));
   set("accept_kill",1);
   setup();
   carry_object(__DIR__"cloth")->wear();
   carry_object(__DIR__"blade")->wield();
}
int accept_kill(object killer,object me)
{
  if(me->query("target_id")!=killer->query("id"))
  return notify_fail("对方根本不理会你的作战请求！\n");
  return 1;
}