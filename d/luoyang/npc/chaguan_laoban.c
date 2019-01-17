
inherit NPC;

#include <ansi.h>

string do_action1();
string do_action2();

void create()
{
   set_name("茶馆老板",({ "lao ban","ban","lao" }) );
        set("gender", "男性" );
        set("age",42);
   set("long", "这是洛阳「山景居」茶铺的老板。\n");       
   set("combat_exp", 50);
   
   set("inquiry",([
    "黄芽叶":(:do_action1:),
    "一等黄芽叶":(:do_action2:),
    ]));
    
   setup();
  
}

string do_action1()
{
   object ob,obj;
   
   ob=this_player();
   
   if(!ob->query_temp("tmz_quest/yun_buy_tea"))
   return "这可是我们茶铺的好茶，我可不会轻易给你！\n";
   ob->delete_temp("tmz_quest/yun_buy_tea");
   
   obj=new(__DIR__"obj/tea");
   obj->move(ob);
   
   tell_object(ob,query("name")+"给了你一"+obj->query("unit")+
                obj->query("name")+"。\n");
   return "原来是阴癸派祝尊者需要此茶，我哪敢不给呢？\n";
}

string do_action2()
{
   object ob,obj;
   
   ob=this_player();
   
   if(!ob->query_temp("tmz_quest/yun_buy_tea"))
   return "这可是我们茶铺的好茶，我可不会轻易给你！\n";
   ob->delete_temp("tmz_quest/yun_buy_tea");
   
   obj=new(__DIR__"obj/tea");
   obj->set("name",HIY"一等黄芽叶"NOR);
   obj->set("super_tea",1);
   obj->move(ob);
   
   tell_object(ob,query("name")+"给了你一"+obj->query("unit")+
                obj->query("name")+"。\n");
   return "原来是阴癸派祝尊者需要此茶，我哪敢不给呢？\n";
}