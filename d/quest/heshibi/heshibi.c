
inherit ITEM;
#include <ansi.h>
int do_absorb();
void create()
{
   set_name(HIW"和氏璧"NOR, ({ "heshibi"}) );
   set_weight(300);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这就是江湖上人人争夺的和氏璧。\n");
     set("material", "玉石");
     set("unit", "块");
     set("value", 40000000000000);
     set("no_sell",1);
   }
   setup();
}

void init()
{
  add_action("do_absorb","absorb");
}

int do_absorb()
{
  object ob;
  ob=this_player();
  if(ob->query("max_force")<800){
  message_vision(HIR"$N只觉得五脏六腹好象火烧一般！\n"NOR,ob);
  ob->unconcious();
  destruct(this_object());
  return 1;}
  message_vision(HIR"$N只觉得五脏六腹好象火烧一般！\n"NOR,ob);
  tell_object(ob,HIC"连忙调整气息，只觉一股热流直朝丹田而来！\n"NOR);
  ob->add("max_force",5);
  ob->unconcious();
  destruct(this_object());
  return 1;
}