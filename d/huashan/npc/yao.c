
inherit NPC;

void create()
{
   set_name("采药人",({ "caiyao ren","ren"}) );
        set("gender", "男性" );
        set("age", 22);
   set("long", "这是在华山采药的人，他对华山的产药处非常熟悉。\n");
       
   set("combat_exp", 20000);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
   set("inquiry",([
	   "采药":"采药吗？华山采药有三处：菩提洞，玉女峰脚下和后山的悬崖。\n",
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

