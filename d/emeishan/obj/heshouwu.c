
inherit ITEM;

void create()
{
        set_name("何首乌", ({ "he shou wu","he","shou","wu" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
				set("long","这是一[何首乌]，是炼制药物极好的药材。\n");
                set("value", 30000);
				set("heal",([
					"heals":30,
					]));
                
        }

      
        setup();
}
