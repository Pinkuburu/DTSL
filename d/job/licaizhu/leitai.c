
inherit ROOM;
#include <ansi.h>
#include <job_money.h>

int do_start();
void create ()
{
  set ("short",HIR"比武招亲擂台"NOR);
  set ("long", @LONG
这里就是杭州李财主的女儿比武招亲的擂台了。只见擂台的
两边挂着幅对联，写着：但求如意郎君共笑江湖 只盼太平天
下齐奏欢歌。 擂台的两边还有几个家丁在把守着。只见这里
人群摩肩接踵，水泻不通，在擂台的边角坐着一个姑娘，脸蒙
红纱，看来就是李财主的女儿了。
LONG);

  set("exits", ([ 

 "down":"/d/hangzhou/houyuan",
         ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_start","biwu");
}

int do_start()
{
  object ob;
  object killer;
  ob=this_player();
  if(!ob->query_temp("li_job"))
  return notify_fail("你一抱双拳，大声道：在下前来比武招亲！\n");
  if(ob->query_temp("target_come")&&
     ob->is_fighting())
  return notify_fail("加油，加油！！\n");
  else if(ob->query_temp("target_come"))
        return notify_fail("你一抱双拳，大声道：在下前来比武招亲！\n");
  message_vision("$N一抱双拳，大声道：在下前来比武招亲！\n",ob);
  if(ob->query("gender")=="女性"){
  message_vision("$N只听下面人群发出一阵轰笑：女人难道来娶女人吗？？\n",ob);
  message_vision("$N立刻羞得满脸通红！\n",ob);}
  if(ob->query("gender")=="男性")
   if(ob->query("age")>50)
    message_vision("$N只听下面人群发出一阵轰笑：你的年纪都可以做人家的爹了！！\n",ob);
  if(ob->query("gender")=="男性")
   if(ob->query("class")=="bonze")
    message_vision("$N只听下面人群发出一阵轰笑：和尚也来娶老婆吗？？！！\n",ob);
  if(ob->query("gender")=="女性"&&
     ob->query("per")>=25)
   message_vision("只听下面有几个地痞流氓朝$N怪笑道：这么漂亮的人，还是嫁给我算了！\n",ob);
  if(ob->query("gender")=="男性"&&ob->query("class")!="bonze")
   if(ob->query("per")<=10)
     message_vision("$N只听下面人群发出一阵轰笑：看看你的相貌，真是癞蛤蟆想吃天鹅肉啊！！\n",ob);
   else
   if(ob->query("per")<=15)
     message_vision("$N只听下面人群发出一阵轰笑：也不回家照照镜子，还好意思来！！\n",ob);
   else
   if(ob->query("per")<=20)
     message_vision("$N只听下面人纷纷议论：这个小子长得不错啊，看来有戏！\n",ob);
   else
    if(ob->query("per")<=25)
     message_vision("$N只听下面人纷纷议论：看他相貌堂堂，只不知武功如何啊！\n",ob);
   else
  message_vision("$N只听下面人暴出一声喝彩：好一个英俊少侠！\n",ob);
  killer=new(__DIR__"guanbing");
  set_all_skill(killer,ob->query("max_pot")-130);
  killer->set("combat_exp",ob->query("combat_exp"));
  killer->set("max_pot",ob->query("max_pot"));
  killer->set("gin",ob->query("max_gin"));
  killer->set("eff_gin",ob->query("max_gin"));
  killer->set("max_gin",ob->query("max_gin"));
  killer->set("kee",ob->query("max_kee"));
  killer->set("eff_kee",ob->query("max_kee"));
  killer->set("max_kee",ob->query("max_kee"));
  killer->set("sen",ob->query("max_sen"));
  killer->set("eff_sen",ob->query("max_sen"));
  killer->set("max_sen",ob->query("max_sen"));
  killer->move(environment(ob));
  killer->set("target_id",ob->query("id"));
  ob->set_temp("target_come",1);
  message_vision("只听蹭地一声，$N跃了上来！\n",killer);
  message_vision(YEL"$N朝$n冷笑道：敢妨碍朝廷办事，你就是找死！！\n"NOR,killer,ob);
  killer->kill_ob(ob);
  return 1;
}
