
inherit NPC;

void create()
{
   set_name("陶叔盛",({ "tao shusheng","tao"}) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "他就是飞马牧场的四大执事之三。\n"); 
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

