
//此任务废除！
#include <ansi.h>

inherit NPC;

void create()
{
   set_name("杨公卿",({ "yang gongqing","yang","gong","qing" }) );
   set("gender", "男性" );
   set("age", 42);
   set("long", "他就是王世充的主要军师人物。\n");
       
   set("combat_exp", 200000);
   set("str", 20);
   set("per", 20);
   set("shili","wang");
   set("attitude", "peaceful");
   set_skill("dodge",100);
   set_skill("unarmed",100);
   set_skill("parry",100);
  
   setup();
   carry_object(__DIR__"guanfu")->wear();
  
}

