
inherit ITEM;

void create()
{
   set_name("佛经", ({ "fojing","fo","jing","book" }));
   set_weight(600);
   set("unit", "本");
   set("long","这是专门介绍[禅宗佛法]的经书.\n");
   set("value", 3000);
   set("skill", ([
     "name":      "chanzong-fofa",    
     "exp_required":   0, 
                         
     "sen_cost":     30,   
     "difficulty":   0, 
     "max_skill":   150,          
   ]) );
}
