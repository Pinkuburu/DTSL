

inherit ITEM;

void create()
{
   set_name("黑铁", ({ "black iron","iron"}) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "iron");
	 set("long","这是一块黑铁，是打造兵器的上好矿石。\n");
     set("unit", "块");
     set("value", 10000);
	 set("weapon",([
		 "damage":150,
		 "strong":150,
		 ]));
    
   }
   setup();
}
