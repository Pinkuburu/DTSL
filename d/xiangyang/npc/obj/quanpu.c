
inherit ITEM;

void create()
{
   set_name("[基本拳脚]拳谱", ({ "quan pu","quan","pu","book" }));
   set_weight(600);
   set("unit", "本");
   set("long","这是专门介绍[基本拳脚]的初级入门拳谱.\n");
   set("value", 1000);
   set("skill", ([
     "name":      "unarmed",    
     "exp_required":   0, 
                         
     "sen_cost":     20,   
     "difficulty":   0, 
     "max_skill":   50,          
   ]) );
}
