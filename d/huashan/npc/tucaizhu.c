
inherit NPC;

void create()
{
   set_name("土财主",({ "tu caizhu","caizhu"}) );
   set("gender", "男性" );
   set("age", 40);
   set("long", "这是一个土财主，正在给自己的女儿找女婿。\n");
       
   set("combat_exp", 20000);
   set("str", 18);
   set("inquiry",([
	   "女婿":"我的女婿一定要有钱，没有钱？想都别想！\n",
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

