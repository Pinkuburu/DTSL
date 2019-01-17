//普通的npc
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("衙役", ({ "ya yi","ya","yi"}) );
       set("gender", "男性" );
       set("age", 28);
       set("long",
               "他是衙门的衙役。\n");
       set("combat_exp", 52500);
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
			say( "衙役说道：这位" + RANK_D->query_respect(ob)
          + "你还是先跪下再说吧!\n");
			break;
		case 1:
			say( "衙役喝道:威~~~~~~~~武。\n");
			break;
	}

}
