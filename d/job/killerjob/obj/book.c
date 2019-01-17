
inherit ITEM;
#include <ansi.h>

void create()
{
   set_name(HIB"《五毒书》"NOR, ({ "book" }));
   set_weight(300);
   set("unit", "本");
   set("long","这是一本关于毒药的书籍。\n");
   set("no_sell",1);
   set("no_drop",1);
   set("no_give",1);
   set("no_get",1);
   set("no_steal",1);
   set("skill", ([
     "name":      "poison",    
     "exp_required":300000, 
                         
     "sen_cost":100,   
     "difficulty":10, 
     "max_skill":80,          
   ]) );
}

