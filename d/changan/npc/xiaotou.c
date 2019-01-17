
inherit NPC;

void create()
{
   set_name("小偷",({ "thief"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是一位在长安城鬼混的小偷。\n");
       
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	object me,ob;
	me=this_object();
	ob=this_player();
	if(ob&&!ob->is_fighting()) call_out("thief",1,me,ob);
}

void thief(object me,object ob)
{
	object money;
	if(me->query("combat_exp")<ob->query("combat_exp"))
	{ message_vision("$N刚想伸手去偷$n的钱，$n怒目一视，$N赶紧缩回手去！\n",me,ob);
	  remove_call_out("thief");
	  return;
	}
	if(random(5)>3)
	{if(!objectp(money=present("silver",ob)))
	{ remove_call_out("thief");return;}
	money->move(me);
	message_vision("$N偷走了$n身上的白银！\n",me,ob);
	}
	remove_call_out("thief");
	return;
}