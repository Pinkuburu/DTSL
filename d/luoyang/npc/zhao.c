
inherit NPC;

void create()
{
   set_name("赵官员",({ "zhao" }) );
        set("gender", "男性" );
        set("age", 42);
   set("long", "他是洛阳城的财政总管，主管洛阳的财政大事。\n");
       
   set("combat_exp", 500000);
   set("shili","luoyang");
   set("str", 10);
   set("per", 22);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/guanfu")->wear();
  
}

/*int accept_object(object who,object ob)
{
	int value,old_value;
	if(ob->query("money_id"))
	{
		value=ob->value();
		if(file_size("/log/guoku/luoyang")>0)
		{
			sscanf(read_file("/log/guoku/luoyang"),"%d",old_value);
			value=value+old_value;
		}
		write_file("/log/guoku/luoyang","",1);
		log_file("guoku/luoyang",sprintf("%d",value));
		message_vision("$N笑道：谢谢了，又为洛阳国库做了贡献!\n",this_object());
		return 1;
	}
	else return notify_fail("这个东西我可不能要!\n");
*/
