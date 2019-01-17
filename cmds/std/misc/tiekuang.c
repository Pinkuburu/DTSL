
inherit ITEM;

#include <ansi.h>

void create()
{
   
   set_name(HIB"铁矿"NOR,({"tiekuang"}));
   set_weight(1000);   
   set("unit", "个");
   set("no_sell",1);
   set("no_save",1);
   set("long","这是一个没有经过识别（ＳＨＩＢＩＥ）的铁矿，你还不知道它的用途。\n");
   setup();
   
}

void init()
{
        add_action("do_shibie","shibie");
}

int set_status(object me)
{
   int dlev;
   int flag=0;
   
   if(me->query("vocation")=="杀手"){
     if(me->query("job_office_number/杀手任务")>=1000
      &&!me->query("find_best_iron")
       ){
       me->set("find_best_iron",1);
       set("dlev",300);//杀手任务1000次，可以得到最好的矿石一次。
       return 1;
     }
    flag=2;
   }
   else flag=0;
  
  dlev=(1+random(2+flag))*50;
  
  set("dlev",dlev);
  
  return 1;
}


int do_shibie()
{
         
         int lev;
         int dlev;
         int dtype;
         int damage,strong;
         
         object me = this_player();    
         object iron = this_object();    
         
        if(me->query("vocation")!="铁匠")
        return notify_fail("你不是铁匠，不能识别铁矿!\n");
        if(iron->query("no_shibie")==1)
                return notify_fail("这个铁矿已经识别过了!\n");
        
        lev=(int)me->query_skill("duanzao-jishu",1);       
        dlev=query("dlev");
        if(lev<dlev){
         
          return notify_fail("你的锻造技术太低了，不足以识别该矿石！\n");
        }
        
        damage=dlev/50*15+random(10);
        strong=dlev/50*30+random(10);
        
        set("weapon/damage",damage);
        set("weapon/strong",strong);
                
        iron->set("long","这是一个铁矿，它的功效指数是：\n伤害："+damage+"\n坚固："+strong+"。\n");
        iron->set("no_shibie",1);
        message_vision("$N将矿石细打量了一遍，终于知道了它的作用！\n",me);
        me->add("vocation_score",1);//加 10 太多了
        message_vision("$N的职业声望增加了。\n",me);

        return 1;
}


