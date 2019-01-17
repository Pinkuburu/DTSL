
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("弟子", ({ "dizi","di","zi"}) );
       set("gender", "男性" );
	   set("title","独尊堡弟子");
       set("age", 25);
       set("long",
               "他是独尊堡的弟子。\n");
       set("combat_exp",40000);
       set("attitude", "peaceful");
	   
	   set("force",300);
	   set("max_force",300);
	   set_skill("unarmed",40);
	   set_skill("dodge",40);
	   set_skill("parry",40);
	   set("chat_chance",30);
	   set("chat_msg",({
		   "弟子纵身而起，喊道：喝！接着一脚踹了出去！\n",
		   "弟子道：我将来一定要成为一个武林高手！\n",
		   "弟子说道：我们堡主是江湖数一数二的英雄！\n"
	   }));
	   setup();
 carry_object(__DIR__"obj/cloth")->wear();
 
}










