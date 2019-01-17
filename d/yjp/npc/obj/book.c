
inherit ITEM;

void create()
{
   set_name("《基本腿法入门》", ({ "leg book","book" }));
   set_weight(200);
   set("unit", "本");
   set("long","这是一本介绍基本腿法的书.\n");
   set("no_drop",1);
   set("no_give",1);
   set("no_steal",1);
   set("skill", ([
     "name":      "leg",    
     "exp_required":   0, 
                         
     "sen_cost":     10,   
     "difficulty":   1, 
     "max_skill":200,          
   ]) );
}
