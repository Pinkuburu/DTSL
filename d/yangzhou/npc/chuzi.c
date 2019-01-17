
inherit NPC;

#include <ansi.h>

int give_food();

void create()
{
   set_name("厨子",({ "chu zi","chu","zi"}) );
        set("gender", "男性" );
        set("age", 32);
        set("target_id","####");
        set("long","这是画舫雇佣的厨子。看起来有些瘦\n");
        
        set("inquiry",([
          "食物":(:give_food:),
          "food":(:give_food:),
          "水":"你可以直接 drink 。\n",
          "water":"你可以直接 drink 。\n",
          "瘦":"没办法啊，这里工作累，我能不瘦么？\n",
          ]));
    setup();
    carry_object("/d/yangzhou/npc/obj/cloth")->wear();
   
}
/*
void init()
{
   object ob;
   
   ob=this_player();
   if(!ob) return;
   remove_call_out("welcome");
   call_out("welcome",1,ob);
}

void welcome(object ob)
{
   if(!ob) return;
   
   if(environment(ob)!=environment())
   return;
   
   
     command("bow "+ob->query("id"));
   
    tell_object(ob,"厨子朝你笑道：如果你想吃东西，请 "+HBMAG+HIW+"ask chu about 食物"+NOR+"。\n");
    tell_object(ob,"厨子朝你笑道：如果你想喝水，请 "+HBMAG+HIW+"drink"+NOR+"。\n");
    
   
  return;
}
*/
int accept_fight(object who)
{
   return 0;
}

void kill_ob(object ob)
{
  ob->remove_killer(this_object());
  command("bi "+ob->query("id"));
  return;
}

int give_food()
{
   object ob,food;
   
   ob=this_player();
   
   if(ob->query("combat_exp")>=20000){
   command("say 你这么高经验还来骗吃骗喝，真是下流！");
   return 1;}
   
   if(present("mantou",ob)){
   
   command("kok "+ob->query("id"));
   command("say 吃完了再要吧！");
   return 1;}
   
   food=new(__DIR__"obj/food");
   food->move(ob);
   
   tell_object(ob,"厨子给了你一"+food->query("unit")+food->query("name")+"。\n");
   
   return 1;
}
   
