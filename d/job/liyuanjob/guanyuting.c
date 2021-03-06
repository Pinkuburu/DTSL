
inherit ROOM;
#include <ansi.h>
#include <job_money.h>
void create()	
{
	set("short", MAG"观雨亭"NOR);
	set("long", @LONG
这里是皇上经常游玩歇息的地方，亭子为于碧波中央，四面绿柳成
荫伴随着悠扬的乐曲，几个绝色的舞女在翩翩起舞，亭子中间是个白玉
石桌桌子上摆满了美酒佳肴，四周是一圈白玉的石椅子 （chair）。你
不禁被眼前的仙境迷住了。
LONG);
        set("exits",([
          "west":"/d/cahc/yuhuayuan",
          ]));
        set("objects",([
          __DIR__"girl1":1,
          __DIR__"girl2":1,
          __DIR__"girl3":1,
          __DIR__"girl4":1,
          ]));
        set("item_desc",([
        "chair":"这是一整块汉白玉雕刻成的石椅。\n",
        ]));
        set("no_fight",1);
 	set("no_quit",1);
        setup();
	
}

void init()
{
  object ob;
  ob=previous_object();
  if(ob->query_temp("liyuan_job/step")!=14)
   return;
  if(ob->query("gender")=="男性")
  call_out("do_ok1",5,ob);
  else call_out("do_ok5",5,ob);
}

void do_ok1(object ob)
{
  if(!ob) return;
  tell_object(ob,HIR"红衣舞女"+NOR+"走到你的面前，伏下身双手奉上一壶美酒。\n");
  call_out("do_ok2",5,ob);
  return;
}

void do_ok2(object ob)
{
  if(!ob) return;
  tell_object(ob,"\n"+BLU+"蓝衣舞女"+NOR+"飘到你的身旁为你轻轻的按摩，把你弄的爽爽的。\n");
  call_out("do_ok3",5,ob);
  return;
}

void do_ok3(object ob)
{
  if(!ob) return;
  tell_object(ob,"\n"+HIG+"绿衣舞女"+NOR+"来到你的身旁轻轻的放在你手上一碗燕窝羹。\n");
  call_out("do_ok4",5,ob);
  return;
}

void do_ok4(object ob)
{
  if(!ob) return;
  tell_object(ob,"\n"+HIY+"黄衣舞女"+NOR+"轻盈的在你的身旁转来转去，不时的向你暗送秋波。\n");
  call_out("do_ok5",5,ob);
  return;
}

void do_ok5(object ob)
{
   int exp,silver,pot;
   
   if(!ob) return;
   
   if(ob->query_temp("killer_comes")<2)
   exp=200+random(50);
   else
   exp=4000+random(50);
   pot=600+random(100);
   silver=8000;
   
   ob->delete_temp("dtsl_job");
   ob->delete_temp("liyuan_job");
   ob->delete_temp("killer_comes");
   
   ob->add("combat_exp",exp);
   ob->add("potential",pot);
   if(ob->query("potential")>ob->query("max_pot")*2)
    ob->set("potential",ob->query("max_pot")*2);
   ob->add("deposit",silver);
   
   tell_object(ob,"\n\n一个管家从里面走了出来，朝你鞠了一个躬！\n"+
      "你在这次行动中得到了"+HIW+chinese_number(exp)+NOR+"点经验，\n"+
      "                    "+HIY+chinese_number(pot)+NOR+"点潜能，\n"+
      "                    "+MONEY_D->money_str(silver)+"\n");
   add_shili(ob,exp/8,silver/8);
   tell_object(ob,"你钱庄的存款增加了！\n");
   
   ob->start_busy(random(2));
   ob->set("busy_time",time());
   return;
}
