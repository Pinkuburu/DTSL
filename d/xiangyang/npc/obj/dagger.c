
inherit ITEM;

void create()
{
   set_name("《短兵刃入门》", ({ "dagger book","book" }));
   set_weight(600);
   set("unit", "本");
   set("long","这是一本介绍短兵刃的书.\n");
   set("value",300);
   set("skill", ([
     "name":      "dagger",    
     "exp_required":1000, 
                         
     "sen_cost":20,   
     "difficulty":3, 
     "max_skill":200,          
   ]) );
}
