
inherit NPC;

int do_action1()
{
   object ob,target;
   int money;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=1000000){
     command("say 你的经验太高了，我已经不能再帮你了。");
     return 1;
   }
   
   if(query("fighter_counts")<=0){
     command("say 目前没有货物了，你等一会再来吧！\n");
     return 1;
   }
   
   
   if(present("liangong_fight_objects",ob)){
    command("say 你一次拿一个就可以了！\n");
    return 1;
   }
   if(ob->query("combat_exp")<100000)
    money=30;
   else
   if(ob->query("combat_exp")<150000)
    money=100;
   else
    money=150;
   
   switch(MONEY_D->player_pay(ob,money)){
     
     case 0:
     case 2:
     command("say 想学我练功的法门也要交点学费吧？");
     return 1;
   }
   add("fighter_counts",-1);
   target=new(__DIR__"obj/mukuai");   
   target->move(ob);
   command("say 这是我练功用的东西，你可以拼装成木头人来练功。");
   return 1;
}

int do_action2()
{
   object ob,target;
   int money;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=1000000){
     command("say 你的经验太高了，我已经不能再帮你了。");
     return 1;
   }
   
   if(query("fighter_counts")<=0){
     command("say 目前没有货物了，你等一会再来吧！\n");
     return 1;
   }
   
   
   if(present("liangong_fight_objects",ob)){
    command("say 你一次拿一个就可以了！\n");
    return 1;
   }
   if(ob->query("combat_exp")<100000)
    money=30;
   else
   if(ob->query("combat_exp")<150000)
    money=100;
   else
    money=150;
   
   switch(MONEY_D->player_pay(ob,money)){
     
     case 0:
     case 2:
     command("say 想学我练功的法门也要交点学费吧？");
     return 1;
   }
   add("fighter_counts",-1);
   target=new(__DIR__"obj/tiekuai");   
   target->move(ob);
   command("say 这是我练功用的东西，你可以拼装成铁罗汉来练功。");
   return 1;
}

int do_action3()
{
   object ob,target;
   int money;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=1000000){
     command("say 你的经验太高了，我已经不能再帮你了。");
     return 1;
   }
   
   if(query("fighter_counts")<=0){
     command("say 目前没有货物了，你等一会再来吧！\n");
     return 1;
   }
   
   
   if(present("liangong_fight_objects",ob)){
    command("say 你一次拿一个就可以了！\n");
    return 1;
   }
   if(ob->query("combat_exp")<100000)
    money=30;
   else
   if(ob->query("combat_exp")<150000)
    money=100;
   else
    money=150;
   
   switch(MONEY_D->player_pay(ob,money)){
     
     case 0:
     case 2:
     command("say 想学我练功的法门也要交点学费吧？");
     return 1;
   }
   add("fighter_counts",-1);
   target=new(__DIR__"obj/pinang");   
   target->move(ob);
   command("say 这是我练功用的东西，你可以拼装成皮傀儡来练功。");
   return 1;
}