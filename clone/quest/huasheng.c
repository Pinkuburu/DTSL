#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
   set_name(HIY"花"HIR"生"NOR, ({"hua sheng","sheng"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这是一粒花生，上面还飘散着巧克力的香味。\n");
     set("unit", "个");
     set("no_decay",1);
     set("value", 200000);
     
   }

}

void init()
{
  add_action("do_eat","eat");
  
}

int do_eat(string arg)
{
  object ob;
  
  ob=this_player();
  
  if(!arg) return 0;
  
  if(!id(arg)) return 0;
  
  message_vision(HIY"$N"HIY"一口吃下了"+query("name")+HIY+"，叫道：真是太爽快了！！\n"NOR,ob);
  
  ob->add("food",1000);
  ob->add("water",1000);  
  
  destruct(this_object());
  
  return 1;
  
}

