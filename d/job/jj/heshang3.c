
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("和尚", ({ "he shang","he","shang"}) );
       set("gender", "男性" );
       set("age", 30);
       set("long","这是这家寺庙的和尚,现在只有他还在这里信守佛法。\n");
       set("combat_exp", 12500);
       set("attitude", "friendly");
       set("class","bonze");
	   /*set("inquiry",([
		   "讲经":(:ask_quest:),
		   ]));*/
       set("jj_flag",3);
       setup();
 carry_object(__DIR__"obj/sengyi")->wear();


}

