
inherit NPC;
#include <ansi.h>
#include <job_money.h>
void create()
{
   set_name("白清儿",({ "bai qinger","bai"}) );
        set("gender", "女性" );
        set("age", 22);
		
   set("long", "她是钱独关的妻子。\n");
       
   set("combat_exp", 300000);
   set("str", 20);
   set("per", 25);
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set("attitude", "peaceful");
   set("chat_chance",70);
   set("chat_msg",({
	   (:random_move:),
   }));
   set("s_flag",2);
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
 
}

