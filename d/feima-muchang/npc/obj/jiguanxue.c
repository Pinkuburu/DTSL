
#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIW"《机关学》"NOR, ({ "jiguan xue","book" }) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","这是一本《机关学》，上面凝结了鲁妙子的心血。\n");
     set("unit", "本");
     set("no_give",1);
     set("no_get",1);
     set("no_drop",1);
     set("no_sell",1);
     set("no_steal",1);
     set("skill", ([
     "name":      "jiguanxue",    
     "exp_required":   0, 
                         
     "sen_cost":     30,   
     "difficulty":   25, 
     "max_skill":   300,          
      ]));
   }
   setup();
}
