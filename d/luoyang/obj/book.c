
inherit ITEM;

void create()
{
   set_name("书卷", ({ "book","steal_busiyin_obj" }) );
   set_weight(100);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "本");
     set("material", "paper");
     set("long", "这是一本书卷，上面似乎记载了某种武功。\n");
     set("nogive_player",1);
     set("no_drop",1);
     set("no_get",1);
     
   }
   
   setup();
}
