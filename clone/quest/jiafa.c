#include <ansi.h>
inherit ITEM;


void create()
{
   set_name(HIW"假发"NOR, ({"jia fa","fa"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这是一个假发。\n");
     set("unit", "个");
     set("value", 400000);
     
   }

}

