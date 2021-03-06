
inherit NPC;

string *names=({
"玉成","yucheng",
"秋","qiu",
"生南","shengnan",
"雄岭","xiongling",
"成天","chengtian",
"金龙","jinlong",
"夏","xia",
"虎","hu",
"志雄","zhixiong",
});

int do_answer(string arg);

void create()
{
   int i;
   i=random(sizeof(names));
   if(i%2!=0)
    i--;   
   set_name("宋"+names[i],({ "song "+names[i+1],"song",names[i+1]}) );
        set("gender", "男性" );
        set("nickname","叛徒");
        set("age", 24);
   set("long", "这是逃出宋家堡的一个叛徒。\n");
       
   set("combat_exp", 70000);
   set_skill("cuff",60);
   set_skill("parry",60);
   set_skill("dodge",60);
   set_skill("force",60);
   
   set_skill("poyu-quan",60);
   set_skill("anxiang-fuying",60);
   
   set("force",200);
   set("max_force",200);
   create_family("宋家堡",7,"弟子");
  
   setup();
   
}

void init()
{
  add_action("do_answer","answer");
}

int set_status(object ob)
{
   set("target_id",ob->query("id"));
   set("last",time());
   set("long",query("long")+"宋家堡已经派"+ob->name()+"杀他了。\n");
   return 1;
}

int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N左右看了看，鬼鬼祟祟地跑了。\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;

}

void dispear()
{
   destruct(this_object());
   return;
}

int surrender()
{
   object ob;
   ob=query_temp("last_damage_from");
   set("touxiang",1);
   if(!ob||
      ob->query("id")!=query("target_id")
      ||
      !ob->is_killing(query("id"))
     )
   return 1;
   remove_killer(ob);
   ob->remove_killer(this_object());
   command("say 唉，我已知自己的过错，看在宋家堡的荣誉份上，\n"+
           "能不能让我自己了断？");
   ob->set_temp("need_answer",this_object());
   return 1;
}
   

int chat()
{
   
   if(clear())
   return 1;
   
   if(  query("eff_kee")*100/query("max_kee")<40
        &&!query("touxiang")
     )
    return surrender();
   
   return ::chat();
}

int do_answer(string arg)
{
   object ob;
   
   ob=this_player();
   
   if(ob->query_temp("need_answer")!=this_object())
   return 0;
   if(!arg)
   return notify_fail("你到底同意还是不同意(answer 能 answer 不能)？\n");
   if(arg=="不能"){
     command("say 好吧！既然如此，我只好拼命了！！");
     kill_ob(ob);
     ob->delete_temp("need_answer");
     return 1;
   }
   ob->delete_temp("need_answer");
   command("say 好！你能为宋家利益考虑，确实是一代豪杰！！");
   message_vision("\n$N挥掌朝自己的天灵盖拍去！\n",this_object());
   ob->set_temp("bai_songshuang/action2",1);
   ob->delete_temp("bai_songshuang/action1");
   ::die();
   return 1;
}