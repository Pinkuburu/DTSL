
inherit NPC;

void create()
{
   set_name("巡捕",({ "xun bu","xun","bu" }) );
        set("gender", "男性" );
        set("age", 12);
   set("long", "这是一个在山海关内巡逻的巡捕。\n");   
   set("combat_exp", 5000+random(5000));
   set("attitude", "peaceful");
   set("chat_chance",50);
   set("chat_msg",({
   	(:random_move:),
   	"巡捕高声喊道：小心盗贼！\n",
   	"巡捕用冷酷的眼神四下打量了一番。\n",
   	}));
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
  
}

