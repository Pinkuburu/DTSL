
inherit NPC;

void create()
{
   set_name("农夫",({ "nong fu","fu"}) );
        set("gender", "男性" );
        set("age",35);
   set("long", "这是一位勤劳的农夫。\n");       
   set("combat_exp",100000);
   set("str", 30);
   set("attitude", "peaceful");
   setup();
  
}

