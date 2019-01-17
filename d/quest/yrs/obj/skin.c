
#include <ansi.h>
inherit ITEM;
int do_wear();
int do_unwear();
void create()
{
        set_name(HIB"人皮"NOR, ({"skin"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
    else  {
           set("unit", "张");
           set("yrs","skin");
           set("long", "这是一张人皮．\n");
           set("armor_prop/armor",1);
        }
}
void init()
{
  add_action("do_wear","wear");
  add_action("do_unwear","unwear");
}

int do_wear()
{
  object ob;
  ob=this_player();
  if(!query("mask"))
  return notify_fail("这么血淋淋的人皮你也戴？\n");
  if(query("use_times")>=8){
  tell_object(ob,"人皮面具逐渐干裂，你眼睁睁地看它碎成粉末，消失在空气之中。\n");
  destruct(this_object());
  return 1;}
  if(query("weared"))
  return notify_fail("你已经戴上了！\n");
  message_vision("$N戴上了一个人皮面具。\n",ob);
  ob->set_temp("apply/name",({query("mask/name")}));
  ob->set_temp("apply/id",({query("mask/id")}));
  //ob->set_temp("apply/short",({query("mask/short")}));
 // ob->set_temp("apply/short",({query("mask/long")}));
  ob->set_temp("apply/yrs",1);
  ob->apply_condition("yrs",query("mask/continue"));
  set("no_drop",1);
  set("no_give",1);
  set("no_sell",1);
  set("no_steal",1);
  set("weared",1);  
  add("use_times",1);
  return 1;
}
int do_unwear()
{
  object ob;
  ob=this_player();
  if(!query("weared"))
  return notify_fail("你并没有戴上人皮面具。\n");
  ob->delete_temp("apply/name");
  ob->delete_temp("apply/id");
  ob->delete_temp("apply/short");
  ob->delete_temp("apply/long");
  ob->delete_temp("apply/yrs");
  delete("no_drop");
  delete("no_give");
  delete("no_sell");
  delete("weared");
  delete("no_steal");
  message_vision("$N脱下了一个人皮面具。\n",ob);
  return 1;
}