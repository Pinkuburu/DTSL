
inherit ITEM;
#include <ansi.h>

void create()
{
   set_name("《基本锤法》", ({ "book" }));
   set_weight(300);
   set("unit", "本");
   set("long","这是东溟派的入门武功指导《基本锤法》。\n");
   set("no_sell",1);
   set("no_drop",1);
   set("no_give",1);
   set("no_get",1);
   set("no_steal",1);
   set("skill", ([
     "name":      "hammer",    
     "exp_required":1, 
                         
     "sen_cost":40,   
 "difficulty":10,
     "max_skill":200,          
   ]) );
}

