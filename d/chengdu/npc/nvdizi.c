
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("弟子", ({ "dizi","di","zi"}) );
       set("gender", "女性" );
	   set("title","独尊堡弟子");
       set("age", 18);
       set("long",
               "她是独尊堡的弟子。\n");
       set("combat_exp",40000);
       set("attitude", "peaceful");
	   
	   set("force",300);
	   set("max_force",300);
	   set_skill("unarmed",40);
	   set_skill("dodge",40);
	   set_skill("parry",40);
	   setup();
 carry_object(__DIR__"obj/cloth")->wear();
 
}










