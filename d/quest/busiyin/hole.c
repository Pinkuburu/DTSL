
inherit ROOM;

void init()
{
	add_action("do_search","search");
	
}

int do_search()
{
	object ob,killer;
	object thing;
	
	ob = this_player();
	
	if(!ob->query_temp("do_bsy_quest2"))
		return 0;
	if(!environment(ob)->query("can_search"))
		return notify_fail("你四下搜索了一下，什么也没发现。\n");
	
	thing = new(__DIR__"obj/thing");
	thing->set_name(environment(ob)->query("can_search/name"),
					environment(ob)->query("can_search/id"));
	environment(ob)->delete("can_search");
	
	thing->move(ob);
	tell_object(ob,"\n你翻了翻地上的土，突然找到了一"+thing->query("unit")+
				thing->query("name")+"！\n\n");
	
	killer = new(__DIR__"npc/killer");
	killer->set_status(ob,1);
	killer->move(environment(ob));
	
	message_vision("\n$N大声喊道："+RANK_D->query_rude(ob)+"，放下你手里的东西，拿命来吧！\n！",
					killer);
	
	killer->kill_ob(ob);
	
	return 1;
	
}