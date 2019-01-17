
 
inherit ITEM;

void create()
{
   set_name("石碑", ({"shi bei","shi","bei"}));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个石碑。\n");
                set("unit", "个");
               
                
        }
}

int is_get_of(object ob,object obj)
{
   ob->set("sen",0);
   ob->set("kee",0);
   return notify_fail("这个石碑太重了，你扛不起来！\n");
}

string long()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("family")||
    ob->query_temp("bai_dongming/action2")
    )
  return query("long");
  
  call_out("killer_come",20,ob);
  ob->set_temp("bai_dongming/action1",1);
  return query("long")+"此山是我开，此树是我栽！要从此路过，留下买路财！\n";
}

void killer_come(object ob)
{
  object killer,guard;
  string msg;
  
  if(!ob||!living(ob)||
     ob->is_ghost()) 
  return;
  
  guard=ob->query_temp("guard_npc");
  if(objectp(guard)&&
     environment(guard)==environment(ob)
    ){
   killer=new(__DIR__"killer");
   killer->move(environment(ob));
   msg="\$N突然跑过来朝$n喝道：不留钱你就留下命吧！\n";
   killer->kill_ob(ob);
   msg+=guard->name()+"拦在$n面前，朝$N冷笑道：就凭你这样的强盗也想害人！\n";
   guard->kill_ob(killer);
   
   message_vision(msg,killer,ob);
   
   COMBAT_D->do_attack(guard,killer,guard->query_temp("weapon"),0,2);
   
   killer->die();
   
   msg="$N惊魂未定之际，只听海边的船上有人娇滴滴地说道："+RANK_D->query_respect(ob)+"为什么给恶人追赶呢？\n";
   msg +="$N答道：多谢救命之恩。我只是路过，却遭他们抢劫。\n";
   msg +="那人继续问道："+RANK_D->query_respect(ob)+"日后有何打算？\n";
   msg +="$N低头道：没做打算。\n";
   msg +="那人淡淡道：那请自便吧！\n";
   message_vision(msg,ob);
   ob->set_temp("bai_dongming/action2",1);
   
  }
  return;
}