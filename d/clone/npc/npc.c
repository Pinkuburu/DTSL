
inherit NPC;

void create()
{
   set_name("非玩家控制人物",({ "npc"}) );
        set("gender", "男性" );
        set("age", 32);
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

