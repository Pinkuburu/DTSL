
inherit NPC;
string give_food();
void create()
{
   set_name("厨子",({ "chu zi","chu","zi" }) );
   set("gender", "男性" );
   set("age", 46);
   set("long", "这是一个厨子。\n");
       
   set("combat_exp",100000);
   set("max_force",300);
   set("force",300);
   set("attitude", "peaceful");
      
   set("inquiry",([
   "食物":(:give_food:),
   "food":(:give_food:),
   ]));
   setup();
}
string give_food()
{
  object ob,food;
  ob=this_player();  
  if(present("mantou",ob))
  return "这不是放着馒头么？还向我要什么？\n";
  food=new(__DIR__"obj/mantou");
  food->move(ob);
  return "好吧，我就给你一个馒头吧！\n";
}
