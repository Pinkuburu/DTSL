

inherit ITEM;

void create()
{
   set_name("密信", ({ "letter","xin" }) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","这是一封记录着辟守玄把柄的信。\n");
	 set("unit", "封");
         set("wanhuan_quest",1);
         set("nogive_player",1);
   }
   setup();
}
