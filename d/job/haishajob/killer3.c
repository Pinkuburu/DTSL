
inherit NPC;
string *name1=({"虚"});
string *name2=({"亮","剑","霸","云","笑","冷","寒","卓"});
void create()
{
   set_name(name1[random(sizeof(name1))]+name2[random(sizeof(name2))]
   ,({ "killer" }) );
   set("class","bonze");
        set("gender", "男性" );
        set("title","静念禅院的叛徒");
        set("age", 32);
   set("long", "这是静念禅院的叛徒。\n");
   set("combat_exp", 800000);
   set("str", 30);
   set("max_gin",2000);
   set("max_kee",2000);
   set("max_sen",2000);
   set("max_force",3000);
   set("force",3000);
   set_skill("force",200);
   set_skill("bikouchan",200);
   set_skill("dujie-zhi",200);
   set_skill("liuyun",200);
   set_skill("finger",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set("hand",({"dujie-zhi"}));
   set("dodge",({"liuyun"}));
   set("force_skill",({"bikouchan"}));
   set("chat_chance_combat",60);
   set("chat_msg_combat",({
   	(:perform_action,"dujie":),
   	}));
   set("accept_kill",1);
   setup();
   carry_object(__DIR__"cloth")->wear();
  
}
int accept_kill(object killer,object me)
{
  if(me->query("target_id")!=killer->query("id"))
  return notify_fail("对方根本不理会你的作战请求！\n");
  return 1;
}