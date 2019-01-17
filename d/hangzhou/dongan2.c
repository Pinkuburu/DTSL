
#include <ansi.h>
inherit ROOM;
#include <job_money.h>

void create ()
{
  set ("short","西湖东岸");
  set ("long", @LONG
这里是西湖的东岸。这里荷花点点，湖面平静如镜。不时有游客从
这里走过。
LONG);

  set("exits", ([ 
 "south":__DIR__"dongan1",
        ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}
void init()
{
	object *ob;object here;int i;
	here=find_object(__DIR__"dongan2");
	ob=all_inventory(here);
	for(i=0;i<sizeof(ob);i++)
	{
		if(ob[i]->query_temp("shang_kill_pantu/6")&&!ob[i]->query_temp("shang_kill_pantu/start"))
		{   ob[i]->set_temp("shang_kill_pantu/start",1);
			call_out("tao_come",1,ob[i]);
		}
	}
	return;
}

void tao_come(object ob)
{
	object killer;
	if(!objectp(ob)) {remove_call_out("tao_come");return;}
	killer=new("/d/job/feima/taoshu-sheng");
	copy_object(killer,ob);
	killer->set_name("陶叔盛",({"tao shusheng","tao"}));
	killer->set("title","叛徒");
	killer->delete("family");
	killer->delete("nickname");
	killer->delete("shili");
	killer->delete("title");
	killer->set("combat_exp",ob->query("combat_exp")*3/2);
	set_all_skill(killer,ob->query("max_pot")-130);
	killer->move(environment(ob));
	message_vision("$N冷笑道:就你也想来杀我!\n",killer);
	killer->kill_ob(ob);
    remove_call_out("tao_come");
	call_out("tao_go",300,killer);
	return;
}

void tao_go(object ob)
{
	if(!objectp(ob)) {remove_call_out("tao_go");return;}
	message_vision("$N觉得不妙,匆匆走了!\n",ob);
	destruct(ob);
    remove_call_out("tao_go");return;
}

