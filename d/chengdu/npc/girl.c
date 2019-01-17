//普通的npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("女孩", ({ "girl"}) );
       set("gender", "女性" );
       set("age", 10);
       set("long",
               "这是一个小女孩。\n");
       set("combat_exp", 12500);
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
			say( "小女孩说道：这位" + RANK_D->query_respect(ob)
          + "你能给我买个花吗?\n");
			break;
		case 1:
			say( "小女孩冲着你笑了笑。\n");
			break;
	}

}
