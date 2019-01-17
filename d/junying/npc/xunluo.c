// bing.c 官兵
#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("巡逻兵", ({ "xunluo bing", "bing" }));
	set("age", 23);
	set("gender", "男性");
	set("long", "他是巡逻兵，他现在正在执行巡逻任务。\n");
	set("attitude", "peaceful");

        set("str", 34);
        set("dex", 36);
	set("combat_exp", 30000);
	set("shen_type", 1);
	setup();
        carry_object("/u/smokes/junying/obj/blade")->wield();
        carry_object("/u/smokes/junying/obj/junfu")->wear();
}

void init()
{
object ob;
ob=this_player();
switch(random(2)+1)
{
case 1:
      remove_call_out("abort");
      call_out("abort",1,ob);
      break;
case 2:
     remove_call_out("killu");
     call_out("killu",1,ob);
     break;
}
}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	kill_ob(me);
	return 1;
}
int abort(object ob)
{
message_vision("巡逻兵仔细打量着$N，说：“你是干什么的？快走！”\n",ob);
return 1;
}
int killu(object ob)
{
message_vision("巡逻兵看了$N一眼，顿起疑心，说：“奸细，快抓起来！”\n",ob);
ob->move("/u/smokes/junying/laofan");
message_vision(HIY"$N被关进了牢房。\n"NOR,ob);
return 1;
}