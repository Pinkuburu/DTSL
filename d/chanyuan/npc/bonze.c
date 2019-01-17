
int do_action2()
{
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->query("family/family_name")!="净念禅院"){
     command("say 你不是本派弟子，问我这个问题做什么？");
     return 1;
   }
   if(ob->query("class")!="bonze"){
     command("say 你还是先出家再说吧。");
     return 1;
   }
   
   if(ob->query("PKS")>=5){
     command("say 你罪孽深重，还敢问我这个问题？");
     return 1;
   }
   if(ob->query("bellicosity")>=100){
     command("say 你杀气深重，还敢问我这个问题？");
     return 1;
   }
   if(ob->query("family/generation")<=5){
     command("say 你可真会说笑。");
     return 1;
   }
   if(ob->query("family/generation")>6){
     command("say 你的辈分太低了。");
     return 1;
   }
   if(ob->query_skill("wuxiang-shengong",1)<150){
     command("say 你的无相神功修为太低了！");
     return 1;
   }
   if(time()-ob->query("mud_flags/try_beifen_time")<300){
     command("say 早和你说过出家人不可浮躁，怎么这么快就忘记了？");
     return 1;
   }
   
   ob->delete("mud_flags/try_beifen_time");
   msg="$N朝$n一笑：好，就让我看看你的功夫如何了！\n";
   message_vision(msg,this_object(),ob);
   
   ob->set_temp("try_beifen",1);
   fight_ob(ob);
   return 1;
}

string no_color(string arg)
{
        arg = replace_string(arg,  BLK, "");
	arg = replace_string(arg,  RED, "");
	arg = replace_string(arg,  GRN, "");
	arg = replace_string(arg,  YEL, "");
	arg = replace_string(arg,  BLU, "");
	arg = replace_string(arg,  MAG, "");
	arg = replace_string(arg,  CYN, "");
	arg = replace_string(arg,  WHT, "");
	arg = replace_string(arg,  HIR, "");
	arg = replace_string(arg,  HIG, "");
	arg = replace_string(arg,  HIY, "");
	arg = replace_string(arg,  HIB, "");
	arg = replace_string(arg,  HIM, "");
	arg = replace_string(arg,  HIC, "");
	arg = replace_string(arg,  HIW, "");
	arg = replace_string(arg,  NOR, "");
	arg = replace_string(arg,  BLINK, "");
	return arg;
}

int surrender(object killer,object victim)
{
   string msg,newname;
   
   if(killer->query_temp("try_beifen")){
      msg="\n$N朝$n一合十，诵了声佛号：阿弥陀佛！看来你的确是进行了一番苦练！\n"+
          "以后你就是本派「不」字辈弟子了！\n\n";
      message_vision(msg,victim,killer);
      newname=killer->query("name");
      newname=no_color(newname);
      newname="不"+newname[2..3];
      killer->set("name",newname);
      tell_object(killer,HIY"以后你的名字是「"+newname+"」\n你成为了净念禅院第五代弟子。\n\n"NOR);
      killer->set("family/generation",5);
      killer->delete_temp("try_beifen");
   }
   return 1;
}

int end_fight(object killer,object victim)
{
     string msg;
   
   if(killer->query_temp("try_beifen")){
      msg="\n$N朝$n唉了一声，说道：“出家人切记不可轻浮，更不可当一天和尚敲一天钟。\n"+
      "继续努力吧！”\n\n";
      message_vision(msg,killer,victim);     
      killer->delete_temp("try_beifen");
      killer->set("mud_flags/try_beifen_time",time());
   }
   return 1;
}	

