
inherit NPC;

void create()
{
   set_name("游客",({ "you ke","you","ke" }) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是一名游客。\n");
       
   set("combat_exp", 5000);
   set("chat_chance",20);
   set("chat_msg",({
     "游客赞道：这里的风景可真美啊！\n",
     "游客东瞅瞅，西看看，不住发出赞美的声音。\n",
   }));
   setup();
 //  carry_object(__DIR__"obj/cloth")->wear();
  
}

