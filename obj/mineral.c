
inherit MONEY;
void create()
{
    set_name("矿石", ({ "mineral"}) );
      set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {  set("prep", "on");
                set("unit", "些");
                set("base_unit","块");
                set("long", "一些矿石。\n");
                set("mineral",1);
                set("base_value",10);
	      
        }
        set_amount(1);
} 