
inherit ITEM;

void create()
{
   set_name("霸刀刀谱", ({ "book"}));
   set_weight(600);
   set("unit", "本");
   set("long","这是一本武林秘籍.\n");
   set("value", 0);
set("no_give",1);
set("no_get",1);
   set("skill", ([
     "name":      "badao",    
     "exp_required":   100000, 
                         
     "sen_cost":     150,   
     "difficulty":   5, 
     "max_skill":   300,          
   ]) );
}
