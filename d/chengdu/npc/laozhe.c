//普通的npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("老者", ({ "old man","man","oldman"}) );
       set("gender", "男性" );
       set("age", 60);
       set("long",
               "这位是久居蜀中的老者。\n");
       set("combat_exp", 32500);
       set("attitude", "friendly");
       
       setup();
 carry_object(__DIR__"obj/cloth")->wear();


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
			say( "老者说道：这位" + RANK_D->query_respect(ob)
          + "我住在这里60几年，有什么事你就问我!\n");
			break;
		case 1:
			say( "老者冲你笑了笑。\n");
			break;
	}

}
