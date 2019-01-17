
#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIW"《武学心法》"NOR, ({ "wuxu xinfa","book","xinfa"}) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","这是一本《武学心法》，讲述了上乘的武功心法。\n");
     set("unit", "本");
     set("value", 10000000000);
     set("skill", ([
     "name":      "wuxue-xinfa",    
     "exp_required":   500000, 
                         
     "sen_cost":     90,   
     "difficulty":   30, 
     "max_skill":   300,          
      ]));
   }
   setup();
}
