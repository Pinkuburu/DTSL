inherit NPC;

void create()
{
  set_name("少女",({ "beauty girl","girl"}) );
        set("gender", "女性" );
        set("age", 18);
   set("per",30);
   set("long", "一个清丽的江南子女，漂亮非常。\n");

   set("attitude", "friendly");
   setup();
    carry_object(__DIR__"shayi")->wear();
}

void init()
{
        object ob,ob2;
        ob=this_player();
        ob2=this_object();
        ::init();
        if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
        call_out("wink",1,ob,ob2);
}

void wink(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting())
    return;
        switch(random(2))
        {
        case 0: message_vision("$N微微笑了笑，少女正值怀春时，不知又想到谁了。\n",ob2);
        break;
        case 1: message_vision("$N用迷人的眼眸对$n眨了眨眼!\n",ob2,ob);
        }
        remove_call_out("wink");
        return;
}
