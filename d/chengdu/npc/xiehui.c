
inherit NPC;
#include <ansi.h>
#include <org.h>
void create()
{
       set_name("解晖", ({ "xie hui","xie"}) );
       set("gender", "男性" );
       set("age", 40);
	   set("title","武林判官");
       set("long",
               "他就是独尊堡的堡主，据说他的武功仅逊色于[天刀]宋缺。\n");
       set("combat_exp", 700500);
       set("attitude", "peaceful");
	   set("gin",1500);
	   set("max_gin",1500);
	   set("kee",1500);
	   set("max_kee",1500);
	   set("sen",1500);
	   set("max_sen",1500);
	   set("max_force",2000);
	   set("force",2000);
	   set_skill("unarmed",160);
	   set_skill("dodge",160);
	   set_skill("parry",160);
           set_skill("force",160);
           set("shili",([
           "name":"duzun_b",
           "leader":"duzun_b",
           ]));
       set("shili_id","xiehui");
       setup();
 carry_object(__DIR__"obj/cloth")->wear();
 

}
int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("我们独尊堡可不要其他帮派的人！\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("我已经不是堡主了，和我说没用的！\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("你高声喊道：独尊堡称雄川中！\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N朝$n笑道：希望$n能好好干，我们独尊堡定会称雄蜀地！\n",ob,me);
	tell_object(me,HIW"\n请去势力名单榜处打 "HIG"join"HIW" 命令就算加入了！\n\n"NOR);
	
	return 1;
}

int accept_gage(object me)
{
   this_object()->fight_ob(me);
   me->fight_ob(this_object());
   return 1;
}