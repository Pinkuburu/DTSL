


inherit ITEM;

void create()
{
   set_name("纸牌", ({ "paper"}) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","这是赌博用的纸牌.\n");
     set("unit", "张");
     set("value", 1);
     set("desc",1);
   }
   setup();
}
