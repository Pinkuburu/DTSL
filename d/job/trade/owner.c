
inherit NPC;

string *name1=({
"马","陈","李","赵","钱","孙","周","吴","王","欧阳"});
string *name2=({
"一","三","五","风","雨","雷","朗","威","民","寄"});
string *id1=({
"ma","chen","li","zhao","qian","sun","zhou","wu","wang","ouyang"});
string *id2=({
"yi","san","wu","feng","yu","lei","lang","wei","min","ji"});

string *gender=({"男性","女性"});

void create()
{
   
   int i,j;
   
   i=random(10);
   j=random(10);
   
   set_name(name1[i]+name2[j],({id1[i]+" "+id2[j],id1[i],id2[j]}) );
        set("gender",gender[random(sizeof(gender))]);
        set("age",30+random(10));
   set("long", "这是一位靠接订货单维持生活的商人。\n"); 
   set("targt_id","####");
   setup();
  
}

int clear()
{
  if(time()-query("last")<500)
  return 0;
  if(!query("no_msg")){
  message_vision("$N匆匆走了。\n",this_object());
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
  return 0;
}

void kill_ob(object ob)
{
   ob->remove_killer(this_object());
   command("grin "+ob->query("id"));
  
   return;
}

int set_status(object ob)
{
   set("long",query("long")+"据说买卖王派"+ob->name()+"来和他订货了。\n");
   set("last",time()+500);
   set("target_id","####");
   return 1;
}