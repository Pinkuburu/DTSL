inherit ITEM;
int do_write(string arg);
void create()
{
   set_name("白纸", ({ "paper"}) );
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("long","这是一张白纸，你可以在上面写字(xie)。\n");
     set("material", "白纸");
     set("unit", "张");
     set("value",2);
   }
   setup();
}

void init()
{
  add_action("do_write","xie");
}

int do_write(string arg)
{
  object ob;
  ob=this_player();
  if(!arg)
  return notify_fail("你要写什么？\n");
  this_object()->set("long","这是一张白纸，上面写着:\n"+arg);
  message_vision("$N在白纸上写了几个字。\n",ob);
  return 1;
}