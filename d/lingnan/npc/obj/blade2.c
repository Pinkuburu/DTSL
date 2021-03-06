
#include <weapon.h>

inherit BLADE;

int do_badao(string arg);

void create()
{
   set_name("单刀", ({ "blade","perform_bajue_blade"}) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("material", "iron");
     set("long", "这是一寻常的单刀，份量大约六、七斤重。\n");
     set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
     set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
     set("no_save",1);
     set("eff_times",3);
     set("nogive_player",1);
     set("no_drop",1);
   }
   init_blade(25,80,80);
   setup();
}

void init()
{
   add_action("do_badao","badao");
}

int wield()
{
      object owner;
      
      if(!environment()) return 0;
      if( !(owner = environment())->is_character() ) return 0;
      return notify_fail("这个东西不能装备。\n");
}


int do_badao(string arg)
{
   object ob;
   int cost;
   string msg;
   int flag=0;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("你要用什么来练习拔刀？\n");
   if(!id(arg))
   return 0;
   if(!ob->query_temp("perform_quest/bajue_action1"))
   return 0;
   if(ob->query("char_lev/perform_bajue_fail"))
   return notify_fail("你不适合练刀的，还是算了吧！\n");
  
   msg="$N手握刀柄，稳定心神，唰地一下拔出了"+query("name")+"！\n";
   
   if( ob->query("MKS")!=ob->query("lingnan_menpai/lingnan_MKS")
    ||ob->query("PKS")!=ob->query("lingnan_menpai/lingnan_PKS")
    ||ob->query("deadtimes")!=ob->query("lingnan_menpai/lingnan_deadtimes")
    ||ob->query("age")>=50
    ||ob->query("kill_same_party_flags")
    ||ob->query("kill_good_party_flags")
    )
    flag=1;
    
   if(!flag){
     msg+="\n$N往后探的手缓慢而稳定，每一分每一寸的移动保持在同一的速度下，其速度均衡\n"+
          "不变。$N的拔刀动作直若与天地和其背后永远隐藏着更深层次的本体结合为一，本身\n"+
          "充满恒常不变中千变万法的味道。没有丝毫空隙破绽可寻，更使人感到随这起手式而\n"+
          "来的第一刀，必是惊天地，泣鬼神，没有开始，没有终结。 \n";
     ob->set("perform_quest/bajue",1);
     msg+="\n$N哈哈一笑，随手扔掉了"+query("name")+"。\n\n";
     message_vision(msg,ob);
     destruct(this_object());
     return 1;
   }
  
    msg+="$N发现没有领会到任何东西，不由得想起宋缺的一句话：\n"+
         "这其中的道理你懂就是懂，不懂就是不懂！\n"+
         "$N突然发现自己不能再钻研天刀八诀，不由得一阵难过，\n"+
         "随手扔掉了"+query("name")+"。\n\n";
    
    message_vision(msg,ob);
    ob->set("char_lev/perform_bajue_fail",1);
    destruct(this_object());
    return 1;
 
}