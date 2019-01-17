
inherit NPC;
#include <ansi.h>
#include <org.h>

void create()
{
   set_name("郑淑明",({ "zheng shuming","zheng"}) );
        set("gender", "女性" );
        set("age", 32);
   set("long", "这是大江联的盟主。\n");
       
   set("combat_exp", 5000);
   set("str", 24);
    set("attitude", "friendly");
    set("shili",([
       "name":"dajiang_b",
       "leader":"dajiang_b",
       ]));
    set("shili_id","dajiang");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
 
}
int accept_enroll(object me)
{
	object ob;
	ob=this_object();
	if(me->query("shili"))
	if(me->query("shili/name")!=ob->query("shili/name"))
	 return notify_fail("我们大江联可不要其他帮派的人！\n");
	if(!ob->query("shili/leader"))
	 return notify_fail("我已经不是盟主了，和我说没用的！\n");
	if(me->query("shili/name")==ob->query("shili/name"))
	 return notify_fail("你高声喊道：大江联雄霸江南！\n");
	me->set_temp("mark_join",ob->query("shili/name"));
	message_vision("$N朝$n笑道：希望$n能好好干，使我们大江联雄霸长江！\n",ob,me);
	tell_object(me,HIW"\n请去势力名单榜处打 "HIG"join"HIW" 命令就算加入了！\n\n"NOR);
	
	return 1;
}

int accept_gage(object me)
{
   this_object()->fight_ob(me);
   me->fight_ob(this_object());
   return 1;
}
