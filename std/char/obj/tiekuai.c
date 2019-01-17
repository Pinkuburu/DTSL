
inherit ITEM;

void create()
{
	set_name("铁块", ({ "tie kuai","tie","kuai","liangong_fight_objects"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("long", "这是一些铁块，可以拼装[pinzhuang]成铁罗汉。\n");
		set("no_give",1);
		
	}
	setup();
}

void init()
{
  add_action("do_action1","pinzhuang");
 
}

int do_action1(string arg)
{
  object ob,target;
  string msg;
  
  ob=this_player();
  
  if(!arg)
  return notify_fail("你要拼装什么？\n");
  if(!id(arg))
  return notify_fail("这个东西不能拼装！\n");
  
  msg="$N把铁块散开，看好每个位置，把铁块拼装成了一个铁罗汉！\n";
  message_vision(msg,ob);
  target=new(__DIR__"fighter2");
  target->set_status(ob);
  target->move(environment(ob));
  ob->add_temp_array("job_temp_killer",target);
  destruct(this_object());
  return 1;
}