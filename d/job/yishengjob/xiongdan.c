#include <ansi.h>

inherit ITEM;

string *heals=({"气血","精神","精血"});

void create()
{
   set_name(HIY"熊胆"NOR,({"xiongdan"}));
   set_weight(500);
   if( clonep() )
     set_default_object(__FILE__);
   else {
                set("unit", "块");
     set("no_sell",1);
//     set("no_give",1);
     set("nogive_player",1);
     set("no_save",1);
     set("long","这是一种珍贵的药材，它能用来炼制药物。\n");
     set("value", 5000);
	set("medicine_type",([
         "type" :heals[random(sizeof(heals))],
         "gongxiao" :10+random(30),
         ])); 
           
   }
   setup();
   
}

string long()
{
  return query("long")+"\n"+"具有治疗"+query("medicine_type/type")+"的功效。\n";
}