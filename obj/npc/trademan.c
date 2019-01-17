
inherit NPC;
int do_teach(string arg);
void create()
{
   set_name("买卖王",({ "maimai wang","maimai","wang"}) );
        set("gender", "男性" );
        set("age", 40);
   set("long", "这是一个商人，人称[买卖王]，他做生意有一套。\n");
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
    set("vocation","商人");
   setup();
   carry_object("/obj/armor/cloth")->wear();
  
}

void init()
{
  add_action("do_teach","qingjiao");
}
int do_teach(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if(!arg)
		return notify_fail("你要向谁请教？\n");
	if(!present(arg,environment(me)))
		return notify_fail("这里没这个人！\n");
	if(me->query("vocation")!="商人")
		return notify_fail("你又不是商人，向我请教什么啊?\n");
	if(me->query("gin")<=3)
		return notify_fail("你太累了，该歇歇了！\n");
        if(me->is_busy())
        return notify_fail("你太忙了！\n");
	switch(MONEY_D->player_pay(me,10)){
		case 0:return notify_fail("买卖王一瞪眼:没学费我怎么教你？\n");
		case 2:return notify_fail("买卖王一笑：我现在不做生意了，银票我怎么找得开？\n");
		default:break;}
	if(me->query("potential")<=0)
	return notify_fail("你的潜能不够了！\n");
	if(me->query_skill("trade",1)>me->query("int")*8)
	return notify_fail("你的讨价还价已经学到极限了，还是自己去练习吧！\n");
	me->add("potential",-1);
	me->improve_skill("trade",me->query("int")/2+random(3));
	me->receive_damage("gin",3+random(3));
	message_vision("$N向$n请教[讨价还价]的问题，觉得有了一些收获。\n",me,ob);
	return 1;
}


