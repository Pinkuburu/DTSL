//普通的npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("武士", ({ "wu shi","wu","shi"}) );
       set("gender", "男性" );
       set("age", 20);
       set("long",
               "他就是行迹蜀中的武士。\n");
       set("combat_exp", 72500);
       set("attitude", "friendly");
       
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 carry_object("/clone/weapon/changjian")->wield();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
	 

	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
		case 0:
			say( "武士说道：这位" + RANK_D->query_respect(ob)
          + "我的武功可不是吹嘘的!\n");
			break;
		case 1:
			say( "武士打量打量了你。\n");
			break;
	}

}
