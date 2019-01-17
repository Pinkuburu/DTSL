
 
inherit ITEM;
inherit F_FOOD;
int do_eat(string arg);
void create()
{
   set_name("荔枝", ({"lizhi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一棵荔枝，看起来还非常新鲜。\n");
                set("no_decay",1);
                set("unit", "个");
                set("value",50);
                set("food_remaining", 30);
                set("food_supply", 40);
        }
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="lizhi")
  return notify_fail("你要吃什么？\n");
  if(!present("lizhi",ob))
  return notify_fail("你身上没有这个东西！\n");
  if(ob->query("water")<ob->max_water_capacity()*2&&
    ob->query("food")<ob->max_food_capacity()*2)
  message_vision("$N吃下了一颗荔枝，觉得舒服极了。\n",ob);
  if(ob->query("food")<ob->max_food_capacity()*2)
  ob->set("food",ob->max_food_capacity()*2);
  if(ob->query("water")<ob->max_water_capacity()*2)
  ob->set("water",ob->max_water_capacity()*2);
  destruct(this_object());
  return 1;
}
