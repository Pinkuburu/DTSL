inherit ROOM;
#include <ansi.h>
int do_zuan(string arg);
void create()
{
	set("short",HIR"北城关帝庙"NOR);
	set("long", @LONG
这里是扬州的北城关帝庙。这里的香火很旺，相对于西城的关帝庙
要好的多。但是近年兵荒马乱，来这里烧香的人也是越来越少了。
LONG);
        set("exits",([
          "west":"/d/yangzhou/beidajie2",
          ]));
	setup();      
}
void init()
{
  object ob;
  add_action("do_zuan","zuan");
  ob=previous_object();
  if(ob->query_temp("dtsl_quest_csj/step3")&&
     !present("shi long")&&
     !present("yuwen huaji")&&
     !query("no_man")){
    set("no_man",1);
    call_out("do_fight",1,ob);}
   return;
}
void do_fight(object ob)
{
  object killer,victim;
  if(!ob){
  remove_call_out("do_fight");
  return;}
  killer=new(__DIR__"npc/yuwen-huaji");
  victim=new(__DIR__"npc/shilong");
  killer->move(environment(ob));
  victim->move(environment(ob));
  killer->kill_ob(victim);
  victim->kill_ob(killer);
  COMBAT_D->do_attack(killer,victim,0,0,2);
  COMBAT_D->do_attack(victim,killer,0,0,2);
  COMBAT_D->do_attack(killer,victim,0,0,2);
  COMBAT_D->do_attack(victim,killer,0,0,2);
  COMBAT_D->do_attack(killer,victim,0,0,2);
  COMBAT_D->do_attack(victim,killer,0,0,2);
  message_vision(HIR"$N一见形式不妙，用尽全身的力气，朝墙壁撞去！只听\n"+
                    "轰地一声，撞出一个大洞！$N身行瞬时消失于黑洞之中！\n"NOR,victim);
  message_vision("$N冷笑道：看你能跑到哪里去！说完身行一晃，踪迹不见！\n",killer);
  destruct(killer);
  destruct(victim);
  remove_call_out("do_fight");
  return;
}
int do_zuan(string arg)
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("dtsl_quest_csj/step3"))
  return 0;
  message_vision("$N朝黑洞中钻了进去！\n",ob);
  ob->set_temp("dtsl_quest_csj/step4");
  ob->move(__DIR__"migong");
  return 1;
}
