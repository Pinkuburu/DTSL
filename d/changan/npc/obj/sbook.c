
inherit ITEM;

void create()
{
        set_name("《基本杖法》", ({"staff book", "book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
   				set("long", "这是一本讲述《基本杖法》的武学书籍。\n");
        		set("material", "paper");
        		set("skill", ([
                        "name": "staff",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 1,
                        "max_skill": 100,
				]) );
        }
}

