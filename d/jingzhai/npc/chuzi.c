
inherit NPC;
string give_food();
void create()
{
   set_name("厨子",({ "chu zi","chu","zi" }) );
   set("gender", "女性" );
   set("age", 46);
   set("long", "这是慈航静斋的厨子。\n");
       
   set("combat_exp",100000);
   set("max_force",300);
   set("force",300);
   set("attitude", "peaceful");
   set_skill("sword",80);
   set_skill("cuff",80);
   set_skill("strike",80);
   set_skill("dodge",80);
   set_skill("finger",80);
   set_skill("literate",80);
   set_skill("force",80);
   set_skill("sekong-jianfa",80);
   set_skill("xiuluo-zhi",80);
   set_skill("wuwang-jing",80);
   set_skill("qingxin-force",80);
   set_skill("lingyun-shenfa",80);
   
   create_family("慈航静斋",8,"弟子");
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
  return "厨子一笑：这不是放着馒头么？还向我要什么？\n";
  food=new("/d/jingzhai/obj/mantou");
  food->move(ob);
  return "好吧，我就给你一个馒头吧！\n";
}
