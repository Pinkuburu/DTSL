
inherit ITEM;

void create()
{
        set_name("《鹫鹰天翔》", ({"jiuying-dodge book", "book","shu"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "本");
          set("long", "这是一本讲述《鹫鹰天翔》的高级武学书籍。\n");
          set("material", "paper");
          set("no_give",1);
          set("no_steal",1);
          set("skill", ([
                        "name": "jiuying-dodge",
                        "exp_required": 500000,
                        "sen_cost": 70,
                        "difficulty":10,
                        "max_skill":200,
          ]));
        }
}

