
inherit ITEM;

void create()
{
   set_name("信物", ({ "xin wu","wu"}) );
   set_weight(1000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一个信物。\n");
     set("unit", "件");
     set("quest_hong",1);
   
   }
   setup();
}
