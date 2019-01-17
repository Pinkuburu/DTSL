
inherit ITEM;
int do_give(string arg);
void create()
{
   set_name("书信", ({ "letter"}) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
     set("long","这是一封普通的书信。\n");
     set("unit", "封");
   }
   setup();
}

void init()
{
  add_action("do_give","song");
}

int do_give(string arg)
{
  object ob;
  object target;
  
  ob=this_player();
  if(!arg)
  return notify_fail("你要把"+query("name")+"送给谁？\n");
  
  if(!ob->query_temp("dtsl_fquest_jz/step5"))
  return notify_fail("你没有资格来送这封信！\n");
  
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("这里没有这个人。\n");
  if(target==ob)
  return notify_fail("把书信送给自己？？\n");
  if(userp(target))
  return notify_fail("对方根本不理会你。\n");
  if(base_name(target)!="/d/changan/npc/lishimin"){
  message_vision("$N笑道：谢谢仙子们看得起我，我一定尽力称霸天下！\n",target);
  destruct(this_object());
  return 1;}
  
  message_vision("$N笑道：我一定不辜负梵师太的期望，进快平定天下，\n"+
                 "使百姓安居乐业！\n",target);
  ob->delete_temp("dtsl_fquest_jz/step5");
  ob->set_temp("dtsl_fquest_jz/step6",1);
  destruct(this_object());
  return 1;
}