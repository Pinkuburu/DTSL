
inherit NPC;
void create()
{
   set_name("刘黑闼",({ "liu heita","liu","heita"}) );
        set("gender", "男性" );
       set("age", 32);
   set("long", "这是窦建德的手下刘黑闼，为人正直朴实。\n");       
   set("combat_exp",300000);
   set("per", 20);
   set("str",28);
   set("max_kee",800);
   set("max_gin",800);
   set("max_sen",800);
   set("max_force",800);
   set("force",800);
   set("attitude", "peaceful");
   set_skill("blade",80);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("force",80);
   set("inquiry",([
   "杨公宝库":"我们一直在找啊，可惜还是没有找到！\n",
   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
}

