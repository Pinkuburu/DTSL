
inherit ITEM;

void create()
{
        set_name("兰草", ({ "lan cao","cao" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
				set("long","这是一棵兰草，可以用来炼药。\n");
                set("value", 3);
				set("wei_med",1);
				set("heal",([
					"heals":50,
					]));
                
        }

      
        setup();
}
