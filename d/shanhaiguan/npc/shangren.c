
inherit NPC;

void create()
{
   set_name("商人",({ "shang ren","ren"}) );
   set("gender", "男性" );
   set("age",30+random(40));
   set("long", "这是一个商人，看起来财大气粗。\n");
       
   set("combat_exp", 200000);
   
   set("chat_chance",20);
   set("chat_msg",({
    "商人呵呵一笑：我专门发战争财，这几年我赚了不少啊！\n",
    "商人道：人不为己，天诛地灭！这年头，谁够狠谁才能活下去！\n",
    "商人琢磨道：下个生意骗谁呢？让我想想看... ...\n",
    "商人冷笑道：谁要是能杀死我，就有机会获得「惩奸除恶」的称号，但是谁敢？\n"+
    "我看哪个敢！！\n",
   }));
   
   setup();
   //carry_object("/d/gaoli/obj/cloth")->wear();
  
}

void die()
{
   object ob;
   
   ob=query_temp("last_damage_from");
   
   if(!ob) return ::die();
   if(!userp(ob)) return ::die();
   
   if(random(100)>95){
     CHANNEL_D->do_channel(this_object(),"rumor",ob->name()+"杀死奸商，获得了"+
      "「惩奸除恶」的称号！\n");
     ob->set_temp("rank/class","惩奸除恶");
   }
   
   return ::die();
   
}