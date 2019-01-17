
inherit ITEM;

void create()
{
        set_name("药鼎", ({ "yao ding","ding","yaoshi_yaoding"}) );
        set("long", "这是一个炼制药物的小鼎。\n");
        set("unit", "个" );
        set("no_give",1);
        set("yaoshi_tool",1);
        set_max_encumbrance(2000000);
        setup();
}

int is_container() { return 1; }

void init()
{
  add_action("do_put","put");

}

int do_put(string arg)
{
   object ob,obj;
   
   ob=this_player();
   
   if(!arg) return notify_fail("你要把什么放到药鼎里？\n");
   obj=present(arg,ob);
   
   if(!obj) return notify_fail("你身上没有这个东西！\n");
   
   if(sizeof(all_inventory(this_object()))>=20)
   return notify_fail("药鼎里的药物太多了！\n");
   
   if(!obj->query("medicine_type")&&
      !obj->query("poison_type")
     )
     return notify_fail("你只能往药鼎中放药物！\n");
   
   message_vision("$N把"+obj->query("name")+"放到了药鼎里。\n",ob);
   
   obj->move(this_object());
   
   return 1;
}