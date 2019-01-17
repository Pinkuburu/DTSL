
inherit ITEM;

#include <ansi.h>

int do_action(string arg);

void create()
{
        set_name(HIY"圣丹"NOR, ({"dan"}));
        set_weight(100);
        
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit","枚");
                set("unit","枚");
   set("long", "这是一枚绝好的丹药，你可以服[fu]它来治愈自己的重伤。\n");
        set("material", "草药");}
    setup();
        
}

void init()
{

  add_action("do_action","fu");
}

int do_action(string arg)
{
   object ob;
   object target;
   
   ob=this_player();
   
   if(!arg)
   return notify_fail("你要服用什么东西？\n");
   if(!objectp(target=present(arg,ob)))
   return notify_fail("你身上没有这个东西。\n");
   if(target!=this_object())
   return 0;
   
   if(query("am"))
   return 0;
   
   if(ob->query("eff_kee")>=ob->query("max_kee"))
    return notify_fail("你现在没有受伤，不用服用丹药。\n");
    set("am",1);
   ob->set("eff_kee",ob->query("max_kee"));
   message_vision("$N服下了"+query("name")+"，面色恢复如初，丝毫看不出受伤的样子。\n",ob);
     call_out("des",1);
   return 1;
}

void des()
{
  destruct(this_object());
  return;
}