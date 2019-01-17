
inherit ITEM;

int do_linghui();

void create()
{
        set_name("《战斗心法》", ({"book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
   set("long", "这是一本《战斗心法》，你可以用它来提高[linghui]自己的经验。\n");
               set("no_give",1);
               set("no_drop",1);
               set("no_get",1);
        set("material", "paper");}
        setup();
}

void init()
{

  add_action("do_linghui","linghui");
}

int do_linghui()
{
   object ob;
   int exp;
   
   ob=this_player();
   
   exp=300+random(10);
   
   ob->add("combat_exp",exp);
   
   tell_object(ob,"你得到了"+chinese_number(exp)+"点经验。\n");
   destruct(this_object());
   return 1;
}