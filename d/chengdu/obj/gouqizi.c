
inherit ITEM;

void create()
{
        set_name("枸杞子", ({ "gou qizi","qizi","qi","zi" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
				set("long","这是一个枸杞子，它能用来炼制药物。\n");
                set("value", 15);
				set("heal",([
					"heals":15,
					]));
                
        }

      
        setup();
}
