#include <ansi.h>
inherit ITEM;


void create()
{
   set_name(HIY"假牙"NOR, ({"jia ya","ya"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这就是真言大师的假牙，看起来.... ....好恶心。\n");
     set("unit", "个");
     set("value", 400000);
     
   }

}

