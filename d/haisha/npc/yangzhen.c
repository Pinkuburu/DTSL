
inherit NPC;

void create()
{
   set_name("杨镇",({ "yang zhen","yang","zhen"}) );
        set("gender", "男性" );
        set("age", 32);
        set("nickname","偃月刀");
   set("long", "这是海沙帮的「偃月刀」杨镇。\n");
       
   set("combat_exp",200000);
   set("attitude", "peaceful");
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);
   set_skill("strike",100);
   set_skill("cuff",100);
   set_skill("blade",100);
   set("shili",([
   "name":"haisha_b",
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wear();
  
}

