
inherit NPC;
#include <ansi.h>

void create()
{
   int i;
   
   set_name("田文",({ "tian wen","tian","wen"}) );
   set("gender", "男性" );
   set("age", 32);
   set("long","他看起来神色慌张。\n");
   set("max_kee",600);
   set("max_gin",100);
   set("max_sen",100);
   set("max_force",100);
   set("force",100);
   set("combat_exp",1);
   
   set("chat_chance",60);
   set("chat_msg",({
     (:random_move:),
   
   }));

    set("last",time());
    setup();
   
   i=random(100);
   if(i>80)
    carry_object(__DIR__"obj/book");
   else
   if(i>70)
    add_money("gold",5);
   else
   if(i>30)
    add_money("silver",30);
   
  
}

