
inherit NPC;

string *name1=({
"马","陈","李","赵","钱","孙","周","吴",
"王"});

void create()
{
   set_name(name1[random(sizeof(name1))]+"家小姐",({ "girl" }) );
        set("gender", "女性" );
        set("con",1);
        set("age", 18);
   set("long", "这是一位富家小姐。\n"); 
   set("per", 25); 
   setup();
  
}

string *mesg=({
"朝你嫣然一笑。",
"朝你眨了眨眼睛。",
"含羞道：别总看着人家嘛！",
"害羞地低下了头。"
});

string long()
{
   string msg;
   
   msg=query("name")+mesg[random(sizeof(mesg))]+"\n";
   return query("long")+msg;
}
   
   

//此物件维持 300 秒
int clear()
{
  if(time()-query("last")<300)
  return 0;
  if(!query("no_msg")){
  message_vision("$N叹道：没意思，去别地方玩了。\n",this_object());
  set("no_msg",1);
  call_out("dispear",1);}
  return 1;
}

void dispear()
{
   destruct(this_object());
   return;
}

int chat()
{
   
   if(clear())
   return 1;
   
   return ::chat();
}

int accept_fight(object who)
{
  return notify_fail(query("name")+"微微一笑：小女子不和人打架的！\n");
}

void kill_ob(object ob)
{
   ob->remove_killer(this_object());
   message_vision("$N朝$n嗔道："+RANK_D->query_respect(ob)+"可别吓我了！\n",
   this_object(),ob);
   return;
}