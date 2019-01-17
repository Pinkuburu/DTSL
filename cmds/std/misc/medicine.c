
inherit ITEM;

#include <medicine.h>

void create()
{
   
   set_name(RED"药材"NOR,({"yaocai"}));
   set_weight(100);   
   set("unit", "包");
   set("no_sell",1);
   set("no_save",1);
   set("long","这是一包没有经过识别（ＳＨＩＢＩＥ）的药材，你还不知道它的用途。\n");
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
         int gongxiao;
         string *types,type;
         
         object me = this_player();    
         object drug = this_object();    
         
        if(me->query("vocation")!="药师")
        return notify_fail("你不是药师，不能识别药品!\n");
        if(drug->query("no_shibie")==1)
                return notify_fail("这个药品已经识别过了!\n");
        
        if(me->query_skill("bencao-shuli",1))
        lev=(int)me->query_skill("bencao-shuli",1);
        else
        lev=(int)me->query_skill("poison",1);
        dlev=query("dlev");
        if(lev<dlev){
          if(me->query_skill("bencao-shuli",1))
          return notify_fail("你的本草术理太低了，不足以识别该药品!\n");
          else
          return notify_fail("你的毒术太低了，不足以识别该药品!\n");
        }
        
        gongxiao=dlev/50*20+random(10);
        //如果是明药师：
        if(me->query_skill("bencao-shuli",1)){
           types=keys(medicine_type);
           dtype=random(M_RAND);//M_RAND定义放到 medicine.h 中，用来调节几率
           type=get_medicine_type(dtype,types);//此函数放到 medicine.h 中。
           set("medicine_type/type",type);
           set("medicine_type/gongxiao",gongxiao);
        }
        else{//如果是暗药师：
        
          types=keys(poison_type);
          dtype=random(P_RAND);//P_RAND定义放到 medicine.h 中，用来调节几率
          type=get_poison_type(dtype,types);//此函数放到 medicine.h 中。 
          set("poison_type/type",type);
          set("poison_type/gongxiao",gongxiao);
        }
                        
        if(me->query_skill("bencao-shuli",1))
        type=HIG+type+NOR;
        else 
        type=HIR+type+NOR;//明药师药材是亮绿色，暗药师是血红色。
        
        drug->set("long","这是一包"+type+"类的药品，它的功效指数是："+gongxiao+"。");
        drug->set("no_shibie",1);
        message_vision("$N将药材仔细打量了一遍，终于知道了它的作用！\n",me);
        set_new_name(this_object());//药材被识别后，名字应该显示出来。
                                    //set_new_name 放到 medicine.h 中。 
        me->add("vocation_score",1);//加 10 太多了
        message_vision("$N的职业声望增加了。\n",me);

        return 1;
}


