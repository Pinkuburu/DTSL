
 
inherit ITEM;

void create()
{
   set_name("鱼钩", ({"yu gou","gou"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一副钓鱼用的鱼钩。\n");
                set("unit", "副");
                set("value",20);
                //set("no_decay",1);
                set("cisha_job",1);
                
        }
}

