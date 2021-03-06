
#include <ansi.h>
#include <org.h>

inherit F_SAVE;
inherit ROOM;

#define LEV1 "民夫"
#define LEV2 "辎重兵"
#define LEV3 "步兵"
#define LEV4 "勇士兵"
#define LEV5 "奇兵"

#define LEV1_MONEY 100
#define LEV2_MONEY 200
#define LEV3_MONEY 200
#define LEV4_MONEY 200
#define LEV5_MONEY 200

#define LEV1_TRAIN 50
#define LEV2_TRAIN 50
#define LEV3_TRAIN 50
#define LEV4_TRAIN 50
#define LEV5_TRAIN 50

#define LEV1_SUPPLY 10
#define LEV2_SUPPLY 50
#define LEV3_SUPPLY 50
#define LEV4_SUPPLY 50
#define LEV5_SUPPLY 50

#define SMALL_CITY_TAX  1600
#define MIDDLE_CITY_TAX 1800
#define BIG_CITY_TAX    1900

string *zainan=({
"发生地震","发生火灾","发生水灾","闹蝗虫","遭遇干旱","遭遇冰雹","遭遇瘟疫",
});

string *goods=({
"丰收","瑞雪兆丰年",
});

string query_save_file()
{
  return "/data/orgroom/"+query("city_id");
}

int is_city_war_room()
{
  return 1;
  
}

void init_war_room()
{
  if(query("lev1_guard")<0) set("lev1_guard",0);
  if(query("lev2_guard")<0) set("lev2_guard",0);
  if(query("lev3_guard")<0) set("lev3_guard",0);
  if(query("lev4_guard")<0) set("lev4_guard",0);
  if(query("lev5_guard")<0) set("lev5_guard",0);
  
  set("guard_person",query("lev1_guard")*LEV1_SUPPLY+query("lev2_guard")*LEV2_SUPPLY+
   query("lev3_guard")*LEV3_SUPPLY+query("lev4_guard")*LEV4_SUPPLY+
   query("lev5_guard")*LEV5_SUPPLY);
  
  if(query("owner")=="wizard"){
   set("lev1_guard",5);
   set("lev2_guard",5);
   set("lev3_guard",5);
   set("lev4_guard",5);
   set("lev5_guard",5);
  }

}

void setup()
{
  
  init_war_room();
  
 delete("do_train");
 delete("do_zhubing");
  ::setup();
  
}


void checkcity()
{
  
  int g_num;
  int deposit,tax;
  int no_reward=0;
  int extra_reward;  
  string msg="";
  object sboard;
 
 init_war_room();
 delete("do_zhubing");
 delete("do_train");
  if(query("owner")!="wizard"){
    g_num=query("guard_person");
    
    if(query("city_type")=="小"){
      add("deposit",-1-random(g_num/100));
    }
    else
    if(query("city_type")=="中等"){
      add("deposit",-4-random(g_num/100));
    }
    else{
     add("deposit",-8-random(g_num/100));
    }
    
    if(query("deposit")<0)
     set("deposit",0);
     
    deposit=query("deposit");
    tax=query("tax");
    
    if(deposit>300) deposit=300;
    if(random(tax-query("zhili_tax")/2)>20){
     if(query("person")>0){
       add("person",-30-random(10));
        if(query("person")<0)
        set("person",0);
       msg=query("city_name")+"因为税率过高，人口减少了！\n";
     }
     no_reward=1;
    }
    else{
     add("person",30+random(10));
      if(query("person")>query("max_person"))
        set("person",query("max_person"));
      add("zhongcheng_du",30+random(10));
     msg=query("city_name")+"的税率合理，百姓的生活安逸舒适，士兵的忠诚度提高了。\n";
    }         
        
    if((g_num>0&&(query("deposit")<g_num/5))||query("deposit")<=0){
      if(query("lev1_guard")>0){      	
       add("lev1_guard",-1);
       add("guard_person",-LEV1_SUPPLY);
      }
      else
      if(query("lev2_guard")>0){      	
       add("lev2_guard",-1);
       add("guard_person",-LEV2_SUPPLY);
      }
      else
      if(query("lev3_guard")>0){      	
       add("lev3_guard",-1);
       add("guard_person",-LEV3_SUPPLY);
      }
      else
      if(query("lev4_guard")>0){      	
       add("lev4_guard",-1);
       add("guard_person",-LEV4_SUPPLY);
      }
     else
     if(query("lev5_guard")>0){      	
       add("lev5_guard",-1);
       add("guard_person",-LEV5_SUPPLY);
     }
      
      no_reward=1;
      msg +="因为"+query("city_name")+"军食短缺，所以有部分士兵开始逃亡了！";
      
    }
   
   if(!no_reward){
     sboard=load_object(BOARD_PATH+query("owner"));
     if(sboard){
       if(query("city_type")=="小"){
        sboard->add("money",query("lev1_guard")*LEV1_SUPPLY*tax*SMALL_CITY_TAX/100);
        sboard->add("exp",query("lev1_guard")*2);
       }
       else
       if(query("city_type")=="中等"){
        sboard->add("money",query("lev1_guard")*LEV1_SUPPLY*tax*MIDDLE_CITY_TAX/100);
        sboard->add("exp",query("lev1_guard")*3);
       }
       else{
        sboard->add("money",query("lev1_guard")*LEV1_SUPPLY*tax*BIG_CITY_TAX/100);
        sboard->add("exp",query("lev1_guard")*4);
       }
       sboard->save();
     }
   }
   
   CHANNEL_D->do_channel(this_object(),"rumor",msg);
   
  }
  else
  if(query("city_time")==60&&query("owner")!="wizard"){
    
    if(query("city_type")=="小"){
        extra_reward=90;
    }
    else
    if(query("city_type")=="中等"){
     extra_reward=75;
    }
    else{
     extra_reward=65;
    }
    if(random(extra_reward)>=60){
      msg=query("city_name")+"收获特产，全城一片欢腾！\n";
      sboard=load_object(BOARD_PATH+query("owner"));
      if(sboard){
      	sboard->add("money",(100-extra_reward)*query("person")*10);
      	sboard->save();
      }
      CHANNEL_D->do_channel(this_object(),"rumor",msg);
    }
  }
  else
  if(query("city_time")==40&&query("owner")!="wizard"&&random(100)>0){
   
   if(random(100)>=40){ 
    msg=query("city_name")+zainan[random(sizeof(zainan))]+"，";
    switch(random(2)){
     case 0:
      add("person",-80-random(80));
      if(query("person")<0)
        set("person",0);
      msg+="导致人口降低了！\n";
      break;
    case 1:
     add("deposit",-8-random(8));
      if(query("deposit")<0)
        set("deposit",0);
      msg+="导致粮食贮备降低了！\n";
    }
    CHANNEL_D->do_channel(this_object(),"rumor",msg);
   }
   else{
    msg=query("city_name")+goods[random(sizeof(goods))]+"，";
    switch(random(2)){
     case 0:
      add("person",80+random(80));
      if(query("person")>query("max_person"))
        set("person",query("max_person"));
      msg+="导致人口提高了！\n";
      break;
    case 1:
     add("deposit",8+random(8));     
      msg+="导致粮食贮备提高了！\n";
    }
    CHANNEL_D->do_channel(this_object(),"rumor",msg);
   }
  }  	  
  
  save();
  
}

void init()
{
  add_action("do_victory",({"victory","zhanling"}));
  add_action("do_zhubing","zhubing");
  add_action("do_check",({"check","chakan"}));
  add_action("do_deposit","deposit");
  add_action("do_chebing","chebing");
  add_action("do_train",({"train","lianbing"}));
  add_action("do_move_guard","diaobing");
  add_action("do_tax","zhishui");
  add_action("do_help","helpcity");
  add_action("do_wuzhuang","wuzhuang");
  add_action("do_chubing","chubing");
  add_action("do_shoubing","shoubing");

}

void rid_no_report()
{
  delete("no_report");
  save();
}

void check_victory()
{
   object *ob;
   int i;
   string guard_type;
   int cost_type;
   
   delete("check_victory");
   message("vision",HIR"【帮会风云】：战火纷纭，"+query("city_name")+"的战事暂停下来，双方铭鼓收兵。\n"NOR,users());
   
   ob=all_inventory(this_object());
   
   for(i=0;i<sizeof(ob);i++)
    if(ob[i]){
      if(!userp(ob[i])){
       if(ob[i]->query("shili/name")==query("owner")&&
          !ob[i]->query("owner_ob")){
       	 guard_type=ob[i]->query("guard_type");
 
         if(guard_type=="lev1") cost_type=LEV1_SUPPLY;
         else
         if(guard_type=="lev2") cost_type=LEV2_SUPPLY;
         else
         if(guard_type=="lev3") cost_type=LEV3_SUPPLY;
         else
         if(guard_type=="lev4") cost_type=LEV4_SUPPLY;
         else
         if(guard_type=="lev5") cost_type=LEV5_SUPPLY;
         
         add(guard_type+"_guard",ob[i]->query("number"));
         ob[i]->set("number",ob[i]->query("number")*COMBAT_D->status(ob[i],1)/100);
         add("guard_person",ob[i]->query("number")*cost_type);         	
         destruct(ob[i]);
      }
      else
       ob[i]->remove_all_killer();
     }
      else
      
       ob[i]->remove_all_killer();
    }
   
   set("war_busy",time());
   save();
   
   return;
}

int do_victory()
{
   object ob;
   object guard1,guard2,guard3,guard4,*guards;
   int i,flag=0;
   
   ob=this_player();
   
if(ob->query("combat_exp")<500000)
return notify_fail("只有经验达到 500K 后才能攻打城市!\n");
   if(time()>query("war_busy")&&time()-query("war_busy")<3600*5)
   return notify_fail("你必须再过一会才可以攻打"+query("city_name")+"。\n");
   
   if(!ob->query("shili/name"))
   return notify_fail("江湖小混混少来这里胡闹！\n");
   
   if(query("owner")==ob->query("shili/name"))
   return notify_fail("这里已经是"+HIY+ORG_D->get_shili(ob)+NOR+"的了！\n");
   
   if(ORG_D->is_friend_org(ob,this_object()))
   return notify_fail("你不能进攻盟友的城市！\n");
   
   remove_call_out("start_zhubing");
   
   if(!query("no_report")){    
    message("vision",HIR"【帮会风云】：天下战火又燃，"NOR+HIY+ORG_D->get_shili(ob)+HIR+"开始进攻"+query("city_name")+"了！\n"NOR,users());
    remove_call_out("rid_no_report");
    set("no_report",1);
    save();
    call_out("rid_no_report",30);
   }
   else{
    delete("no_report");
    tell_object(this_object(),HIY+ORG_D->get_shili(ob)+NOR+"开始进攻"+query("city_name")+"了！\n");
    save();
   }
   
   if(!query("check_victory")){
      set("check_victory",1);
      remove_call_out("check_victory");
      call_out("check_victory",300);
   
       
    if(query("lev1_guard")){
     guard1=new(__DIR__"npc/guard");
     add("lev1_guard",-1);
     guard1->set_status(1,"lev1",query("apply/armor"),query("apply/damage"),query("owner"));
     guard1->move(this_object());
     guard1->set("shili/name",query("owner"));
    }
    if(query("lev2_guard")){
     guard1=new(__DIR__"npc/guard");
     add("lev2_guard",-1);
     guard1->set_status(1,"lev2",query("apply/armor"),query("apply/damage"),query("owner"));
     guard1->move(this_object());
     guard1->set("shili/name",query("owner"));
    }
    if(query("lev3_guard")){
     guard1=new(__DIR__"npc/guard");
     add("lev3_guard",-1);
     guard1->set_status(1,"lev3",query("apply/armor"),query("apply/damage"),query("owner"));
     guard1->move(this_object());
     guard1->set("shili/name",query("owner"));
    }
    if(query("lev4_guard")){
     guard1=new(__DIR__"npc/guard");
     add("lev4_guard",-1);
     guard1->set_status(1,"lev4",query("apply/armor"),query("apply/damage"),query("owner"));
     guard1->move(this_object());
     guard1->set("shili/name",query("owner"));
    }
    if(query("lev5_guard")){
     guard1=new(__DIR__"npc/guard");
     add("lev5_guard",-1);
     guard1->set_status(1,"lev5",query("apply/armor"),query("apply/damage"),query("owner"));
     guard1->move(this_object());
     guard1->set("shili/name",query("owner"));
    }
   }
   guards=all_inventory(this_object());
   
   for(i=0;i<sizeof(guards);i++)
    if(guards[i]&&!userp(guards[i])
     &&guards[i]->query("shili/name")==query("owner")
      ){
    	flag=1;
    	break;
    }
    
  
   if(flag)
    return notify_fail("你还先把敌人杀光吧！\n");
   
   remove_call_out("check_victory");
   
   message("vision",HIR"【帮会风云】：一方战火平息，"NOR+HIY+ORG_D->get_shili(ob)+HIR+"已经占领了"+query("city_name")+"！\n"NOR,users());
   
   set("owner",ob->query("shili/name"));
   set("shili/name",ob->query("shili/name"));
   delete("check_victory");
   delete("no_report");
   delete("lev1_guard");
   delete("lev2_guard");
   delete("lev3_guard");
   delete("lev4_guard");
   delete("lev5_guard");
   delete("city_time");
   delete("money");
   delete("lev1_guard_trains");
   delete("lev2_guard_trains");
   delete("lev3_guard_trains");
   delete("lev4_guard_trains");
   delete("lev5_guard_trains");
  delete("zhili_tax");
   add("person",-query("person")/50);
   delete("guard_person");
   set("war_busy",time());
   save();
   
   return 1;
   
}

int do_zhubing(string arg)
{
  object ob;
  object sboard;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<300000)
   return notify_fail("只有经验达到了 300，000 才可以进行驻兵！\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("江湖小混混少来这里胡闹！\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("这里不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方！\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("你所能治理的城市是"+HIY+ob->query("shili/wide")+NOR+"，而不是"+HIY+query("city_name")+NOR+"！\n");
    else
    return notify_fail("你不能治理"+HIY+query("city_name")+NOR+"！\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>4)
     &&!ob->query("shili/leader"))
  return notify_fail("以你的权利目前不能给"+HIY+query("city_name")+NOR+"驻兵！\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("帮会出了问题，请报告巫师！\n");
  
  if(!arg||(arg!=LEV1)
   )
  return notify_fail("请使用 zhubing "+LEV1+"。\n");
  
    if(sboard->query("money")<LEV1_MONEY)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"现在没有这么多钱来驻兵！\n");
    
    if(query("guard_person")>=query("person"))
    return notify_fail("你必须继续提高"+HIY+query("city_name")+NOR+"的人口，否则无法驻兵！\n");
    
    if(query("do_zhubing")>=5)
    return notify_fail("城市不能一次驻扎太多的民夫，你等一会吧！\n");
    
    add("do_zhubing",1);
    
    tell_object(ob,"你决定在"+HIY+query("city_name")+NOR+"驻扎一些兵力。\n");
    
    call_out("start_zhubing",180,ob->name(),ob->query("shili/name"),sboard);
        
    save();
    sboard->save();
  return 1;
  
}

void start_zhubing(string name,string org_name,object sboard)
{
  
  if(!sboard)
  	sboard=load_object(BOARD_PATH+org_name);
  
  if(!name||!org_name||!sboard){
  	add("do_zhubing",-1);
  	return;
  }
 
  sboard->set("shili/name",org_name);
  CHANNEL_D->do_channel(sboard,"banghui",name+"在"+query("city_name")+"驻扎了一些"+LEV1+"！\n");
  
  sboard->add("money",-LEV1_MONEY);
  add("lev1_guard",1);
  add("guard_person",LEV1_SUPPLY);
  add("do_zhubing",-1);
  
  save();
  sboard->save();
  
}


int do_deposit(string arg)
{
  object ob;
  object sboard;
  int num;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<300000)
   return notify_fail("只有经验达到了 300，000 才可以进行囤积粮食！\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("江湖小混混少来这里胡闹！\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("这里不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方！\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("你所能治理的城市是"+HIY+ob->query("shili/wide")+NOR+"，而不是"+HIY+query("city_name")+NOR+"！\n");
    else
    return notify_fail("你不能治理"+HIY+query("city_name")+NOR+"！\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>4)
     &&!ob->query("shili/leader"))
  return notify_fail("以你的权利目前不能给"+HIY+query("city_name")+NOR+"囤积粮食！\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("帮会出了问题，请报告巫师！\n");
  
  if(!arg||sscanf(arg,"%d",num)!=1)
   return notify_fail("你要囤积多少吨粮食？一两黄金/吨粮食\n");
  
  if(num<=0)
   return notify_fail("不要捣乱！\n");
  
  if(sboard->query("money")<num*10000)
   return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"现在没有这么多钱来囤积粮食！\n");
  
  sboard->set("shili/name",ob->query("shili/name"));
  CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"在"+query("city_name")+"囤积了"+
     chinese_number(num)+"吨粮食！\n");
  sboard->delete("shili/name");
  
  sboard->add("money",-num*10000);
  sboard->save();
  add("deposit",num);
  save();
  
  return 1;
}

int do_train(string arg)
{
  object ob;
  object sboard;
  int num;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("只有经验达到了 500，000 才可以进行练兵！\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("江湖小混混少来这里胡闹！\n");
  
  if(!ob->query_skill("qianjun-shu",1))
   return notify_fail("你必须学会「千军术」才可以练习士兵！\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("这里不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方！\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("你所能治理的城市是"+HIY+ob->query("shili/wide")+NOR+"，而不是"+HIY+query("city_name")+NOR+"！\n");
    else
    return notify_fail("你不能治理"+HIY+query("city_name")+NOR+"！\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>2)
     &&!ob->query("shili/leader"))
  return notify_fail("以你的权利目前不能给"+HIY+query("city_name")+NOR+"训练军队！\n");
  
  if(ob->query("vocation")!="杀手")
  return notify_fail("只有杀手可以训练士兵！\n");
  
  if(query("do_train")>=5)
   return notify_fail("已经有太多人练兵，可怜可怜民夫吧！\n");
  
  if(ob->query_temp("start_do_train"))
  return notify_fail("你正在训练士兵！\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("帮会出了问题，请报告巫师！\n");
  
  if(!arg||
     (arg!=LEV2&&arg!=LEV3&&arg!=LEV4&&arg!=LEV5)
    )
  return notify_fail("你要训练哪一类士兵？"+LEV2+" "+LEV3+" "+LEV4+" "+LEV5+"。\n");    
    
  if(arg==LEV2){
    if(!query("lev1_guard"))
     return notify_fail(HIY+query("city_name")+NOR+"还没有驻扎"+LEV1+"。\n");
    if(sboard->query("money")<LEV2_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"现在没有这么多钱来训练"+LEV2+"！\n");
     
     tell_object(ob,"\n你开始训练士兵！\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV2,1,environment(ob),LEV2_TRAIN);
     return 1;
  }
  else
  if(arg==LEV3){
    if(!query("lev1_guard"))
     return notify_fail(HIY+query("city_name")+NOR+"还没有驻扎"+LEV1+"。\n");
    if(sboard->query("money")<LEV3_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"现在没有这么多钱来训练"+LEV3+"！\n");
     
     tell_object(ob,"\n你开始训练士兵！\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV3,1,environment(ob),LEV3_TRAIN);
     return 1;
  }
  else
  if(arg==LEV4){
    if(!query("lev1_guard"))
     return notify_fail(HIY+query("city_name")+NOR+"还没有驻扎"+LEV1+"。\n");
    if(sboard->query("money")<LEV4_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"现在没有这么多钱来训练"+LEV4+"！\n");
     
     tell_object(ob,"\n你开始训练士兵！\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV4,1,environment(ob),LEV4_TRAIN);
     return 1;
  }
  else
  if(arg==LEV5){
    if(!query("lev1_guard"))
     return notify_fail(HIY+query("city_name")+NOR+"还没有驻扎"+LEV1+"。\n");
    if(sboard->query("money")<LEV5_TRAIN)
     return notify_fail(HIY+ORG_D->get_shili(ob)+NOR+"现在没有这么多钱来训练"+LEV5+"！\n");
     
     tell_object(ob,"\n你开始训练士兵！\n");
     ob->set_temp("start_do_train",1);
     add("do_train",1);
     call_out("start_train",1,ob,sboard,LEV5,1,environment(ob),LEV5_TRAIN);
     return 1;
  }
  
  return 1;
 
}

void start_train(object ob,object sboard,string level,int times,object where,int cost)
{
   if(!ob){
     add("do_train",-1);
     save();
     return;
   }
   if(environment(ob)!=where){
     tell_object(ob,"你结束了练兵！\n");
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     save();
     return;
   }
   
   if(times>=30){
     tell_object(ob,"\n你让士兵们停下来，休息一下。\n");
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     save();
     return;
   }
   
   if(!objectp(sboard))
     sboard=load_object(BOARD_PATH+ob->query("shili/name"));
   
   if(!objectp(sboard)){
      tell_object(ob,"帮会练兵出错，请报告巫师。\n");
      return;
   }
   
   if(sboard->query("money")<cost){
     tell_object(ob,HIY"\n你们帮会的储备不够了！\n"NOR);
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     save();
     return;
   }
   
   if(ob->query("gin")<=50){
    tell_object(ob,HIR"\n你筋疲力尽，决定停下来休息一下。\n"NOR);
     ob->delete_temp("start_do_train");
     add("do_train",-1);
     save();
     return;
   }
   
   ob->receive_damage("gin",50);
   
   if(level==LEV2){
     add("lev2_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     sboard->save();
     if(query("lev2_guard_trains")>=2000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV2_SUPPLY>query("person")){
        tell_object(ob,"你该继续提高"+HIY+query("city_name")+NOR+"的人口了！\n");
        return;
      }
      if(query("lev2_guard")<query("apply/armor")/3){
       tell_object(ob,"你该提高"+HIY+query("city_name")+NOR+"的装甲了！\n");
       return;
      }
      if(query("lev2_guard")<query("apply/damage")/2){
       tell_object(ob,"你该提高"+HIY+query("city_name")+NOR+"的武器装备了！\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","据说"+query("city_name")+"的"+level+"增强了！\n");
     add("lev2_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV2_SUPPLY);
     set("lev2_guard_trains",0);
     save();
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }
  
  if(level==LEV3){
     add("lev3_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     sboard->save();
     if(query("lev3_guard_trains")>=2000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV3_SUPPLY>query("person")){
        tell_object(ob,"你该继续提高"+HIY+query("city_name")+NOR+"的人口了！\n");
        return;
      }
      if(query("lev3_guard")<query("apply/armor")/3){
       tell_object(ob,"你该提高"+HIY+query("city_name")+NOR+"的装甲了！\n");
       return;
      }
      if(query("lev3_guard")<query("apply/damage")/2){
       tell_object(ob,"你该提高"+HIY+query("city_name")+NOR+"的武器装备了！\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","据说"+query("city_name")+"的"+level+"增强了！\n");
     add("lev3_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV3_SUPPLY);
     set("lev3_guard_trains",0);
     save();
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }
 
 if(level==LEV4){
     add("lev4_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     sboard->save();
     if(query("lev4_guard_trains")>=2000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV4_SUPPLY>query("person")){
        tell_object(ob,"你该继续提高"+HIY+query("city_name")+NOR+"的人口了！\n");
        return;
      }
      if(query("lev4_guard")<query("apply/armor")/3){
       tell_object(ob,"你该提高"+HIY+query("city_name")+NOR+"的装甲了！\n");
       return;
      }
      if(query("lev4_guard")<query("apply/damage")/2){
       tell_object(ob,"你该提高"+HIY+query("city_name")+NOR+"的武器装备了！\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","据说"+query("city_name")+"的"+level+"增强了！\n");
     add("lev4_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV4_SUPPLY);
     set("lev4_guard_trains",0);
     save();
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }     
  
  if(level==LEV5){
     add("lev5_guard_trains",1+ob->query_skill("qianjun-shu",1)/10);
     sboard->add("money",-cost);
     sboard->save();
     if(query("lev5_guard_trains")>=2000){
      
      if(query("guard_person")-LEV1_SUPPLY+LEV5_SUPPLY>query("person")){
        tell_object(ob,"你该继续提高"+HIY+query("city_name")+NOR+"的人口了！\n");
        return;
      }
      if(query("lev5_guard")<query("apply/armor")/3){
       tell_object(ob,"你该提高"+HIY+query("city_name")+NOR+"的装甲了！\n");
       return;
      }
      if(query("lev5_guard")<query("apply/damage")/2){
       tell_object(ob,"你该提高"+HIY+query("city_name")+NOR+"的武器装备了！\n");
       return;
      }
     CHANNEL_D->do_channel(this_object(),"rumor","据说"+query("city_name")+"的"+level+"增强了！\n");
     add("lev5_guard",1);
     add("lev1_guard",-1);
     add("guard_person",-LEV1_SUPPLY+LEV5_SUPPLY);
     set("lev5_guard_trains",0);
     save();
    }
    call_out("start_train",1,ob,sboard,level,times+1,where,cost);
    return;
  }  
  
}
     

int do_move_guard(string arg)
{
  object ob,guard,*guards;
  object source_city;
  string city,type,guard_type;
  int num,i,j;
  int cost_type;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("只有经验达到了 500，000 才可以进行调兵！\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("江湖小混混少来这里胡闹！\n");
   
  if(ob->query("shili/name")!=query("owner")
   &&!ORG_D->if_friend_org(ob,source_city))
  return notify_fail("这里不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方，也不是你的同盟！\n");
  
  if(!arg||sscanf(arg,"%s %d %s",city,num,type)!=3)
  return notify_fail("你要从哪里调多少什么级别的士兵到这里来？(diaobing 城市 数量 士兵)\n");
  
  if(!type||
     (type!=LEV1&&type!=LEV2&&type!=LEV3&&type!=LEV4&&type!=LEV5)
    )
  return notify_fail("你要调集哪一类士兵？"+LEV1+" "+LEV2+" "+LEV3+" "+LEV4+" "+LEV5+"。\n");
  
  if(num<=0||num>=100)
  return notify_fail("不要捣乱！！！\n");
  
  source_city=load_object(__DIR__+city);
  if(!source_city)
  return notify_fail("目前大唐中不存在这样的城市！\n");
  
  if(source_city==this_object())
  return notify_fail("不要捣乱！！！\n");
  
  if(ob->query("shili/name")!=source_city->query("owner"))
  return notify_fail(HIY+source_city->query("city_name")+NOR+"不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方！\n");
  
  if(ob->query("shili/wide")!=source_city->query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("你所能治理的城市是"+HIY+ob->query("shili/wide")+NOR+"，而不是"+HIY+source_city->query("city_name")+NOR+"！\n");
    else
    return notify_fail("你不能治理"+HIY+source_city->query("city_name")+NOR+"！\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>2)
     &&!ob->query("shili/leader"))
  return notify_fail("以你的权利目前不能从"+HIY+source_city->query("city_name")+NOR+"调兵！\n");
  
  if(type==LEV1) guard_type="lev1";
  else
  if(type==LEV2) guard_type="lev2";
  else
  if(type==LEV3) guard_type="lev3";
  else
  if(type==LEV4) guard_type="lev4";
  else
  if(type==LEV5) guard_type="lev5";
  
  if(type==LEV1) cost_type=LEV1_SUPPLY;
  else
  if(type==LEV2) cost_type=LEV2_SUPPLY;
  else
  if(type==LEV3) cost_type=LEV3_SUPPLY;
  else
  if(type==LEV4) cost_type=LEV4_SUPPLY;
  else
  if(type==LEV5) cost_type=LEV5_SUPPLY;  
  
  if(num>source_city->query(guard_type+"_guard"))
  return notify_fail("目前"+HIY+source_city->query("city_name")+NOR+"没有这么多此类型的士兵！\n");
  
  if(query("guard_person")+num*cost_type>query("person"))
    return notify_fail("你必须继续提高"+HIY+query("city_name")+NOR+"的人口，否则无法调兵过来！\n");
      
  if(query("check_victory")){
    guard=new(__DIR__"npc/guard");
    guard->set_status(num,guard_type,source_city->query("apply/armor"),source_city->query("apply/damage"),source_city->query("owner"));
    guard->move(environment(ob));
  }
  add(guard_type+"_guard",num);  
  source_city->add(guard_type+"_guard",-num);
  add("guard_person",num*cost_type);
  source_city->add("guard_person",-num*cost_type);
  
  save();
  source_city->save();
  
  guards=all_inventory(source_city);
  
  for(i=0,j=0;i<sizeof(guards);i++){
    if(!userp(guards[i])&&guards[i]->query(guard_type)
      &&guards[i]->query("shili/name")==source_city->query("owner")){
     j++;
     destruct(guards[i]);
    }
    if(j>=num) break;
  }
  
  CHANNEL_D->do_channel(this_object(),"rumor","据说有一支军队从"+source_city->query("city_name")+
   "进军到了"+query("city_name")+"。\n");
  
  return 1;

}
            

int do_chebing(string arg)
{
  object ob;
  object sboard;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("只有经验达到了 500，000 才可以进行撤兵！\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("江湖小混混少来这里胡闹！\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("这里不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方！\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("你所能治理的城市是"+HIY+ob->query("shili/wide")+NOR+"，而不是"+HIY+query("city_name")+NOR+"！\n");
    else
    return notify_fail("你不能治理"+HIY+query("city_name")+NOR+"！\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>3)
     &&!ob->query("shili/leader"))
  return notify_fail("以你的权利目前不能给"+HIY+query("city_name")+NOR+"撤兵！\n");
  
  sboard=load_object(BOARD_PATH+ob->query("shili/name"));
  
  if(!sboard)
  return notify_fail("帮会出了问题，请报告巫师！\n");
  
  if(!arg||
   (arg!=LEV1&&arg!=LEV2&&arg!=LEV3&&arg!=LEV4&&arg!=LEV5)
   )
  return notify_fail("请使用 chebing "+LEV1+"/"+LEV2+"/"+LEV3+"/"+LEV4+"/"+LEV5+"。\n");
  
  if(arg==LEV1){
    
    if(query("lev1_guard")<=0)
    return notify_fail(query("city_name")+"没有驻扎"+LEV1+"！\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"从"+query("city_name")+"撤消了一些"+LEV1+"！\n");
    sboard->add("money",LEV1_MONEY/3);
    add("lev1_guard",-1);
    add("guard_person",-LEV1_SUPPLY);
    save();
    
  }
  if(arg==LEV2){
    if(query("lev2_guard")<=0)
    return notify_fail(query("city_name")+"没有驻扎"+LEV2+"！\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"从"+query("city_name")+"撤消了一些"+LEV2+"！\n");
    sboard->add("money",LEV2_MONEY/3);
    add("lev2_guard",-1);
    add("guard_person",-LEV2_SUPPLY);
    save();
    
  }
  if(arg==LEV3){
    if(query("lev3_guard")<=0)
    return notify_fail(query("city_name")+"没有驻扎"+LEV3+"！\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"从"+query("city_name")+"撤消了一些"+LEV3+"！\n");
    sboard->add("money",LEV3_MONEY/3);
    add("lev3_guard",-1);
    add("guard_person",-LEV3_SUPPLY);
    save();
    
  }
  if(arg==LEV4){
    if(query("lev4_guard")<=0)
    return notify_fail(query("city_name")+"没有驻扎"+LEV4+"！\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"从"+query("city_name")+"撤消了一些"+LEV4+"！\n");
    sboard->add("money",LEV4_MONEY/3);
    add("lev4_guard",-1);
    add("guard_person",-LEV4_SUPPLY);
    save();
    
  }
  if(arg==LEV5){
    if(query("lev5_guard")<=0)
    return notify_fail(query("city_name")+"没有驻扎"+LEV5+"！\n");
    sboard->set("shili/name",ob->query("shili/name"));
    CHANNEL_D->do_channel(sboard,"banghui",ob->name()+"从"+query("city_name")+"撤消了一些"+LEV5+"！\n");
    sboard->add("money",LEV5_MONEY/3);
    add("lev5_guard",-1);
    add("guard_person",-LEV5_SUPPLY);
    save();
    
  }
  sboard->save();
  return 1;
  
}

int do_tax(string arg)
{
  object ob;
  int tax;
  string msg;
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("只有经验达到了 500，000 才可以进行治税！\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("江湖小混混少来这里胡闹！\n");
  
  if(!ob->query_skill("dadao-qishu",1))
   return notify_fail("你必须学会「大道奇书」才可以治理城市！\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("这里不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方！\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("你所能治理的城市是"+HIY+ob->query("shili/wide")+NOR+"，而不是"+HIY+query("city_name")+NOR+"！\n");
    else
    return notify_fail("你不能治理"+HIY+query("city_name")+NOR+"！\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>3)
     &&!ob->query("shili/leader"))
  return notify_fail("以你的权利目前不能给"+HIY+query("city_name")+NOR+"调节税率！\n");
  
  if(time()>query("tax_busy")&&time()-query("tax_busy")<15*60)
  return notify_fail("要过一刻钟后你才可以继续调节税率！\n");
  
  if(!arg||sscanf(arg,"%d",tax)!=1)
  return notify_fail("你要如何调节税率？zhishui 税率(0-100)\n");
  
  if(tax<0||tax>100)
  return notify_fail("不要捣乱！！\n");
  
  if(query("tax")<tax) msg="提高了";
  else
  if(query("tax")>tax) msg="降低了";
  else msg="保持不变";
  
  CHANNEL_D->do_channel(this_object(),"rumor","据说"+query("city_name")+"的税率"+msg+"。\n");
  
  set("tax",tax);
  set("zhili_tax",tax*ob->query_skill("dadao-qishu",1)/300);
  set("tax_busy",time());
  
  save();
  
  return 1;
  
}

int do_wuzhuang(string arg)
{
   
  object ob,obj;
  
  
  ob=this_player();
  
  if(ob->query("combat_exp")<400000)
   return notify_fail("只有经验达到了 400，000 才可以进行武装！\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("江湖小混混少来这里胡闹！\n");
  
  if(!ob->query_skill("junxie-xue",1))
  return notify_fail("你必须学了「军械学」才可以武装城市！\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("这里不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方！\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("你所能治理的城市是"+HIY+ob->query("shili/wide")+NOR+"，而不是"+HIY+query("city_name")+NOR+"！\n");
    else
    return notify_fail("你不能治理"+HIY+query("city_name")+NOR+"！\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>6)
     &&!ob->query("shili/leader"))
  return notify_fail("以你的权利目前不能武装"+HIY+query("city_name")+NOR+"的军队！\n");
  
  if(ob->query("vocation")!="铁匠")
  return notify_fail("只有铁匠才可以武装"+HIY+query("city_name")+NOR+"的军队！\n");
  
  if(!arg) return notify_fail("你要拿什么来增加军队的武装？\n");
  obj=present(arg,ob);
  if(!obj) return notify_fail("你身上没有这个东西！\n");
  
  if( obj->query("rumor")
    ||obj->query("no_save")
    ||obj->query("no_sell")
    ||obj->query("no_get")
    ||obj->query("no_give")
    ||obj->query("nogive_player")
    )
    return notify_fail("这个东西不能用来增加军队的武装！\n");
  
  if(!obj->query("armor_prop")&&!obj->query("weapon_prop"))
  return notify_fail("你只能用“盔甲”或“兵器”来增加军队的武装。\n");
  
  add("apply/armor",(obj->query("armor_prop/armor")/15)*ob->query_skill("junxie-xue",1)/200);
  add("apply/damage",(obj->query("weapon_prop/damage")/15)*ob->query_skill("junxie-xue",1)/200);
  
  if(obj->query("equipped"))
   obj->unequip();
  
  destruct(obj);
  
  save();
  
  set("shili/name",ob->query("shili/name"));
  set("channel_id",ORG_D->get_shili(ob));
  CHANNEL_D->do_channel(this_object(),"banghui",ob->name()+"增加了"+query("city_name")+"的军队武装！\n");
  set("shili/name",0);
  set("channel_id",0);
  
  return 1;

}

int if_do_action(object ob,string type)
{
  
  if(type=="lev1") return 1;
  
  if(ob->query_skill("war-heal",1)&&
   type=="lev2")
  return 1;
  
  if(ob->query_skill("bafang-zhenfa",1)&&
   type=="lev3")
  return 1;
  
  if(ob->query_skill("liaoyuan-tianshu",1)&&
   type=="lev4")
  return 1;
  
  if(ob->query_skill("wuxing-qishu",1)&&
   type=="lev5")
  return 1;
  
  return 0;
  
}

int do_chubing(string arg)
{
  
  object ob,guard;
  int num,cost_type;
  string type,guard_type;
  
  
  ob=this_player();
  
  if(ob->query("combat_exp")<500000)
   return notify_fail("只有经验达到了 500，000 才可以进行出兵！\n");
  
  if(objectp(ob->query_temp("city_war_guard")))
  return notify_fail("你已经带兵了。\n");
  
  if(ob->query("pker"))
  return notify_fail("通缉犯老实点吧！\n");
  
  if(time()>ob->query("war_guard_busy")&&time()-ob->query("war_guard_busy")<60*20)
   return notify_fail("你不能连续带兵！\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("江湖小混混少来这里胡闹！\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("这里不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方！\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("你所能治理的城市是"+HIY+ob->query("shili/wide")+NOR+"，而不是"+HIY+query("city_name")+NOR+"！\n");
    else
    return notify_fail("你不能治理"+HIY+query("city_name")+NOR+"！\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>2)
     &&!ob->query("shili/leader"))
  return notify_fail("以你的权利目前不能从"+HIY+query("city_name")+NOR+"出兵！\n");
  
  if(!arg||sscanf(arg,"%d %s",num,type)!=2)
  return notify_fail("你要出 多少 什么种类 的兵？chubing 数量 类型\n");
  
  if(num<=0||num>=100)
   return notify_fail("不要捣乱！！\n");
  if(type!=LEV1&&type!=LEV2&&type!=LEV3&&type!=LEV4&&type!=LEV5)
  return notify_fail("你要出什么类型的兵？"+LEV1+" "+LEV2+" "+LEV3+" "+LEV4+" "+LEV5+"\n");
  
  if(type==LEV1) guard_type="lev1";
  else
  if(type==LEV2) guard_type="lev2";
  else
  if(type==LEV3) guard_type="lev3";
  else
  if(type==LEV4) guard_type="lev4";
  else
  if(type==LEV5) guard_type="lev5";
  
  if(type==LEV1) cost_type=LEV1_SUPPLY;
  else
  if(type==LEV2) cost_type=LEV2_SUPPLY;
  else
  if(type==LEV3) cost_type=LEV3_SUPPLY;
  else
  if(type==LEV4) cost_type=LEV4_SUPPLY;
  else
  if(type==LEV5) cost_type=LEV5_SUPPLY;
  
  if(num>query(guard_type+"_guard"))
  return notify_fail(HIY+query("city_name")+NOR+"没有这么多的"+type+"。\n");
  
  if(!if_do_action(ob,guard_type))
  return notify_fail("你学的技能不能指挥此类士兵！\n");
  
  add(guard_type+"_guard",-num);
  add("guard_person",-num*cost_type);
  
  guard=new(__DIR__"npc/guard");
  guard->set_status(num,guard_type,query("apply/armor"),query("apply/damage"),query("owner"));
  guard->set("zhongcheng_du",query("zhongcheng_du"));
  
  guard->add_temp("damage",ob->query_skill("bafang-zhenfa",1)/5);
  guard->add_temp("damage",ob->query_skill("liaoyuan-tianshu",1)/5);
  guard->add_temp("damage",ob->query_skill("wuxing-qishu",1)/5);
  
  guard->move(environment(ob));
  guard->check_owner(ob);
  guard->set("owner_ob",ob);
  ob->set_temp("city_war_guard",guard);
  ob->set("war_guard_busy",time());
  ob->set_temp("dtsl_job","war");
  
  save();
  
  set("shili/name",ob->query("shili/name"));
  set("channel_id",ORG_D->get_shili(ob));
  CHANNEL_D->do_channel(this_object(),"banghui",ob->name()+"从"+query("city_name")+"派出了"+
    chinese_number(num*cost_type)+"人的"+type+"！\n");
  set("shili/name",0);
  set("channel_id",0);
  
  CHANNEL_D->do_channel(this_object(),"rumor","据说"+query("city_name")+"派出了一些士兵！\n");
  
  return 1;
  
}     
  

int do_shoubing()
{
  
  object ob,guard;
  int cost_type;
  string guard_type;
  
  
  ob=this_player();
  
  if(!objectp(guard=ob->query_temp("city_war_guard")))
  return notify_fail("你没有带兵。\n");
  
  if(!ob->query("shili/name"))
   return notify_fail("江湖小混混少来这里胡闹！\n");
   
  if(ob->query("shili/name")!=query("owner"))
  return notify_fail("这里不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方！\n");
  
  if(ob->query("shili/wide")!=query("city_name")&&!ob->query("shili/leader")){
    if(	ob->query("shili/wide"))
    return notify_fail("你所能治理的城市是"+HIY+ob->query("shili/wide")+NOR+"，而不是"+HIY+query("city_name")+NOR+"！\n");
    else
    return notify_fail("你不能治理"+HIY+query("city_name")+NOR+"！\n");
  }
  
  if( (!ob->query("shili/power")||ob->query("shili/power")>2)
     &&!ob->query("shili/leader"))
  return notify_fail("以你的权利目前不能在"+HIY+query("city_name")+NOR+"收兵！\n");
  
  
  guard_type=guard->query("guard_type");
 
  if(guard_type=="lev1") cost_type=LEV1_SUPPLY;
  else
  if(guard_type=="lev2") cost_type=LEV2_SUPPLY;
  else
  if(guard_type=="lev3") cost_type=LEV3_SUPPLY;
  else
  if(guard_type=="lev4") cost_type=LEV4_SUPPLY;
  else
  if(guard_type=="lev5") cost_type=LEV5_SUPPLY;
  
  guard->set("number",guard->query("number")*COMBAT_D->status(guard,1)/100);
  
  if(query("guard_person")+cost_type*guard->query("number")>query("person"))
  return notify_fail("你必须先提高"+HIY+query("city_name")+NOR+"的人口。\n");
  
  add(guard_type+"_guard",guard->query("number"));
  add("guard_person",guard->query("number")*cost_type);
  
  ob->set_temp("city_war_guard",0);
  ob->delete_temp("dtsl_job");
  
  destruct(guard);
  
  save();
  
  set("shili/name",ob->query("shili/name"));
  set("channel_id",ORG_D->get_shili(ob));
  CHANNEL_D->do_channel(this_object(),"banghui",ob->name()+"将一些出征的士兵派回了"+query("city_name")+"！\n");
  set("shili/name",0);
  set("channel_id",0);
  
  return 1;
  
}     
  

int do_check()
{
  object ob;
  string msg,org_msg;
  int flag=0;
  
  ob=this_player();
  
  if(!wizardp(ob)&&ob->query("shili/name")!=query("owner")){
    if(!ob->query_skill("zhencha-shu",1))
    return notify_fail("这里不是"+HIY+ORG_D->get_shili(ob)+NOR+"所占领的地方！\n");
    else
    flag=1;
  }
  
  if(query("owner")&&query("owner")!="wizard")
   org_msg=ORG_D->get_board_shili(query("owner"));
  else
   org_msg="朝廷";
  
  msg=HIY+query("city_name")+"目前治理情况：\n"NOR;
  msg+=HIY"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
  msg+="在"+HIY+org_msg+NOR+"的统治下。\n\n"NOR;
  msg+="类型：属于"+query("city_type")+"城市\n";
  msg+="人口上限："+chinese_number(query("max_person"))+"人\n";
  
  if(!flag)
  msg+="目前人口："+chinese_number(query("person"))+"人\n";
  else
  msg+="目前人口："+chinese_number(query("person")+random(200-ob->query_skill("zhencha-shu",1)))+"人\n";
  
  if(!flag)
  msg+="士兵人口："+chinese_number(query("guard_person"))+"人\n";
  else
  msg+="士兵人口："+chinese_number(query("guard_person")+random(200-ob->query_skill("zhencha-shu",1)))+"人\n";
  
  msg+="税率："+query("tax")+"%\n";
  msg+="忠诚度："+query("zhongcheng_du")+"\n";
  msg+=HIR"兵力：\n"NOR;
  if(!flag)
  msg+=LEV1+"："+chinese_number(query("lev1_guard"))+"人   "+"单位所占人口："+chinese_number(LEV1_SUPPLY)+"人\n";
  else
  msg+=LEV1+"："+chinese_number(query("lev1_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "人   "+"单位所占人口："+chinese_number(LEV1_SUPPLY)+"人\n";

  if(!flag)
  msg+=LEV2+"："+chinese_number(query("lev2_guard"))+"人   "+"单位所占人口："+chinese_number(LEV2_SUPPLY)+"人\n";
  else
  msg+=LEV2+"："+chinese_number(query("lev2_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "人   "+"单位所占人口："+chinese_number(LEV2_SUPPLY)+"人\n";  
  
  if(!flag)
  msg+=LEV3+"："+chinese_number(query("lev3_guard"))+"人   "+"单位所占人口："+chinese_number(LEV3_SUPPLY)+"人\n";
  else
  msg+=LEV3+"："+chinese_number(query("lev3_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "人   "+"单位所占人口："+chinese_number(LEV3_SUPPLY)+"人\n";
  
  if(!flag)
  msg+=LEV4+"："+chinese_number(query("lev4_guard"))+"人   "+"单位所占人口："+chinese_number(LEV4_SUPPLY)+"人\n";
  else
  msg+=LEV4+"："+chinese_number(query("lev4_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
     "人   "+"单位所占人口："+chinese_number(LEV4_SUPPLY)+"人\n";
  
  if(!flag)
  msg+=LEV5+"："+chinese_number(query("lev5_guard"))+"人   "+"单位所占人口："+chinese_number(LEV5_SUPPLY)+"人\n";
  else
    msg+=LEV5+"："+chinese_number(query("lev5_guard")+random(200-ob->query_skill("zhencha-shu",1)))+
    "人   "+"单位所占人口："+chinese_number(LEV5_SUPPLY)+"人\n";
 
  
  msg+=HIR"\n武装：\n"NOR;
  
  if(!flag)
  msg+="装甲："+chinese_number(query("apply/armor"))+"\n";
  else
  msg+="装甲："+chinese_number(query("apply/armor")+random(200-ob->query_skill("zhencha-shu",1)))+"\n";
  
  if(!flag)
msg+="武器："+chinese_number(query("apply/damage"))+"\n";
  else
msg+="武器："+chinese_number(query("apply/damage")+random(200-ob->query_skill("zhencha-shu",1)))+"\n";
  
  msg+=WHT"粮食储备："NOR+chinese_number(query("deposit"))+"吨\n";
  msg+=HIY"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR;
  
  ob->start_more(msg);
  
  return 1;
}

int do_help()
{
  string msg;
  
  msg="\n以下是有关城市治理的一些命令(详细的内容还请参见help war)：\n\n";
  msg+="victory/zhanling：此命令用于占领一个城市时使用。\n";
  msg+="zhubing：此命令用于在城市中驻扎兵力。\n";
  msg+="chebing：此命令用于撤消已经驻扎的一些兵力。\n";
  msg+="chubing：此命令用于出兵来攻击别的城市。\n";
  msg+="shoubing：此命令用于收回已经派出的一些兵力。\n";
  msg+="train/lianbing：此命令用于训练士兵，以提高等级。\n";
  msg+="deposit：此命令用于囤积粮食。\n";
  msg+="diaobing：此命令用于调兵，来支其他城市的防守。\n";
  msg+="zhuishui：此命令用于治理城市的税率。\n";
  msg+="wuzhuang：此命令用于加强城市的武装。\n";
  msg+="check/chakan：此命令用于查看城市的信息。\n";
  
  this_player()->start_more(msg);
  return 1;
}
