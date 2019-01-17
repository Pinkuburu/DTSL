
inherit NPC;
#include <ansi.h>
string do_quest();
void create()
{
   set_name("画师",({ "hua shi","shi"}) );
        set("gender", "男性" );
        set("age",55);
   set("long","他是一个画师。\n");
   set("max_kee",300);
   set("max_gin",300);
   set("max_sen",300);
   set("combat_exp",200000);
   set("inquiry",([
     "画画":"我的画很好，可是如今却没有人赏识，唉......\n",
     "画笔":(:do_quest:),
     ]));
   setup();
    
}
void die()
{
  message_vision(HIR"$N纵声一叹：没想到我一个画师都没有生存之地！\n"NOR,this_object());
  return ::die();
}

string do_quest()
{
  object ob;
  object tool;
  ob=this_player();
  if(!ob->query_temp("yrs_find/pencil"))
  return "你不懂绘画，拿了我的画笔也没用的！\n";
  tool=new(__DIR__"obj/pencil");
  tool->move(this_object());
  return "哼，想拿我的画笔，先杀了我再说好了！！\n";
}