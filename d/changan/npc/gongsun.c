
inherit NPC;
string give_book();
void create()
{
   set_name("公孙武师",({ "gongsun wushi","wushi","gongsun" }) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是长安武馆的教头，在长安有不少弟子。\n");
       
   set("combat_exp", 120000);
   set("str", 28);
   set("per", 23);
   set("attitude", "peaceful");
   set_skill("unarmed",90);
   set_skill("parry",90);
   set_skill("dodge",90);
   set_skill("force",90);
   set("max_force",500);
   set("force",500);
   set("inquiry",([
	   "基本拳脚":(:give_book:),
	   ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
string give_book()
{
	object me,ob,book;
	me=this_player();ob=this_object();
	if(me->query_skill("unarmed",1)>100)
		return "你的功夫不低了，太客气了！\n";
	if(ob->query("get_book"))
		if(ob->query("get_book")==me->name())
			return "我不是刚给你一本书吗？你快去学习吧！\n";
		else return "我刚给了"+ob->query("get_book")+"一本《基本拳脚》，你去找他要吧！\n";
	ob->set("get_book",me->name());
	book=new(__DIR__"obj/ubook");
	tell_object(me,""+ob->name()+"给了你一本《基本拳脚》。\n");
	book->move(me);
	return ""+RANK_D->query_respect(me)+",你真是该好好学学基本功夫了！\n";
}
