
inherit NPC;

int do_quest1();
int do_quest2();

void create()
{
   set_name("韩泽南",({ "han zenan","han"}) );
        set("gender", "男性" );
		
        set("age", 25);
   set("long", "这是洪小裳的丈夫。\n");
       
   set("combat_exp",50000);
   
   set("inquiry",([
     "小杰":(:do_quest1:),
     "信物":(:do_quest2:),
     ]));
   
   setup();
  
}

int do_quest1()
{
   object ob;
   
   ob=this_player();
   
   if(!ob->query_temp("tmz_quest/hong_step1")){
     command("say 你说什么呢？我可是什么也不知道！\n");
     return 1;
   }
   
   ob->delete_temp("tmz_quest/hong_step1");
   ob->set_temp("tmz_quest/hong_step2",1);
   
   command("fear");
   command("say 你...你...你是谁，怎么知道我和小裳的孩子的名字？");
   command("say 这位"+RANK_D->query_respect(ob)+"，求求你高台贵手，\n"+
           "放过我们吧！\n");
   return 1;
} 

int do_quest2()
{
   object ob,obj;
   string msg;
   
   ob=this_player();
   
   if(!ob->query_temp("tmz_quest/hong_step2")){
     command("say 你说什么呢？我可是什么也不知道！\n");
     return 1;
   }
   msg="$N冷冷道：我虽是阴癸派弟子，但也不是毫无人性！\n"+
       "只要你们给我「天魔阵」的书籍，我自然会放过你们！\n";
   message_vision(msg,ob);
   msg="$N高兴地说道：那谢谢这位"+RANK_D->query_respect(ob)+"了！\n";
   message_vision(msg,this_object());
   
   obj=new(__DIR__"obj/xinwu");
   obj->move(ob);
   tell_object(ob,query("name")+"给了你一"+obj->query("unit")+
              obj->query("name")+"。\n");
   return 1;
}