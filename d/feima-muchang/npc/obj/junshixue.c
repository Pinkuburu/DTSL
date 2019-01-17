
#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIW"《军事学》"NOR, ({ "junshi xue","book" }) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","这是一本《军事学》，上面讲述了各种兵法。\n");
     set("unit", "本");
     set("value", 10000000000);
     set("skill", ([
     "name":      "junshixue",    
     "exp_required":   300000, 
                         
     "sen_cost":     50,   
     "difficulty":   30, 
     "max_skill":   300,          
      ]));
   }
   setup();
}
