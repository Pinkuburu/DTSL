inherit ITEM;
void create()
{
	set_name("首级", ({ "shouji"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("value", 1);
		set("material", "meat");
		}
	if(clonep(this_object())) call_out("decay", 1200, 1);
        setup();
}

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
        switch(phase) {
                case 1:
                        say( query("name")+"开始逐渐腐烂了，发出一股难闻的恶臭。\n");
                        delete_temp("apply");
                        set_name("腐烂的人头", ({ "head" }));
                        set("long", "这是一颗腐烂了的人头，正散发着一股腐尸的味道。\n");
                        delete("victim_user");  
                        delete("kill_by");
                        call_out("decay", 180, phase + 1);
                        break;
                case 2:
                        say( query("name")+"被风吹干了，变成一颗骷髅。\n" );
                        set_name("骷髅", ({ "skull" }) );
                        set("long", "这是一颗人类的骷髅。\n");
                        call_out("decay", 120, phase + 1);
                        break;
                case 3:
                        say( "一阵风吹过，把"+query("name")+"化成灰吹散了。\n");                       
                        destruct(this_object());
                        break;
        }
}
