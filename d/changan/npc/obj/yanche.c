


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
   if(clonep(this_object())) call_out("disappear",180,this_object());
   setup();
}

void disappear(object ob)
{
	tell_object(environment(ob),"一个官兵走了过来，看到盐车，将盐车赶走了！\n");
	destruct(ob);
	remove_call_out("disappear");
	return;
}
