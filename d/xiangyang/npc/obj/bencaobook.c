
inherit ITEM;

void create()
{
   set_name("《本草术理》", ({ "bencao book","shu","book" }));
   set_weight(600);
   set("unit", "本");
   set("long","这是一本讲述本草术理的书。\n");
   set("skill", ([
     "name":      "bencao-shuli",    
     "exp_required":400000, 
                         
     "sen_cost":     40,   
     "difficulty":   1, 
     "max_skill":   50,          
   ]) );
}
