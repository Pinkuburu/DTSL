

inherit ITEM;
void create()
{
   set_name("盐车", ({ "yan che","che"}) );
   set_weight(10000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
	 set("long","这是一辆运盐的车.\n");
     set("unit", "辆");
     
  }  
   setup();
}

int clean_up()
{
   if(time()-query("last_time")>900)
 { delete("no_clean_up");return 1;}
   return 0;
} 


int is_get_of(object me,object ob)
{
  return notify_fail("看清楚这样东西你能捡起来吗？\n");
}
