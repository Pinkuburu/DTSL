
inherit ITEM;

void create()
{
        set_name("天魔阵", ({"tianmozhen book", "book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
        set("long", "这是一本记载天魔阵的书籍。\n");
        set("material", "paper");
        set("no_give",1);
        set("no_get",1);
        set("no_drop",1);
        set("no_steal",1);
        set("skill", ([
                        "name": "tianmo-zhen",
                        "exp_required":200000,
                        "sen_cost":50,
                        "difficulty":2,
                        "max_skill": 20,
]) );
        }
}

