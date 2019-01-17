
inherit NPC;
string *name1=({"尚"});
string *name2=({"亮","剑","霸","云","笑","冷","寒","卓"});
void create()
{
   set_name(name1[random(sizeof(name1))]+name2[random(sizeof(name2))]
   ,({ "killer" }) );
        set("gender", "男性" );
        set("title","东溟派的叛徒");
        set("age", 32);
   set("long", "这是东溟派的叛徒。\n");
   set("combat_exp", 800000);
   set("str", 30);
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",3000);
   set("force",3000);
   set_skill("force",200);
   set_skill("piaomeng-jianfa",200);
   set_skill("sword",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("nishang-piaoming",200);
   set("dodge",({"nishang-piaoming"}));
   set("sword",({"piaomeng-jianfa"}));
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
   	(:perform_action,"lianhuan":),
   	}));
   set("accept_kill",1);
   setup();
   carry_object(__DIR__"cloth")->wear();
   carry_object(__DIR__"changjian")->wield();
}
int accept_kill(object killer,object me)
{
  if(me->query("target_id")!=killer->query("id"))
  return notify_fail("对方根本不理会你的作战请求！\n");
  return 1;
}