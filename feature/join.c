
#include <dbase.h>

int do_join()
{
	object me,ob;string *killed_shili,shili,me_shili;
	
	me=this_player();
	ob=this_object();

	killed_shili=me->query("killed_shili");
	shili=ob->query("shili");
	me_shili=me->query("shili");
  if(shili==me_shili)
	  return notify_fail("你不是已经加入了吗?\n");
   if(me->query("king")) return notify_fail("我们可不敢收势力的头领啊！\n");
	if(sizeof(killed_shili)>0)
		if(sizeof(killed_shili-({shili}))<sizeof(killed_shili))
		return notify_fail("你杀了我们势力的人，还想加入?\n");
	message_vision("$N笑道:好,这位"+RANK_D->query_respect(me)+",以后你就是本势力的人了!\n",ob);
	me->set("shili",shili);
	me->set("guanzhi","帮众");
	log_file("shili/"+shili,sprintf("帮众.\n"));
	return 1;
}

int do_shengzhi()
{
	object me,ob;int score;
	me=this_player();ob=this_object();
    score=me->query("chaoting_score");
	if(me->query("shili")!=ob->query("shili"))
		return notify_fail("你不是我们的人，我怎么能给你升官？\n");
    if(score<30000) return notify_fail("你还是再为朝廷出些力气吧！\n");
	if(score<100000)
		if(me->query("guanzhi")=="shibing")
		{ message_vision("$N笑道：好啊，"+RANK_D->query_respect(me)+",以后你就是校尉了！\n",ob);
		  me->set("guanzhi","xiaowei");
		  return 1;
		}
		else if(me->query("guanzhi")=="xiaowei")
			 return notify_fail("你还是再为朝廷出些力气吧！\n");
	if(score<500000)
		if(me->query("guanzhi")=="shibing"||me->query("guanzhi")=="xiaowei")
		{
			message_vision("$N笑道：好啊，"+RANK_D->query_respect(me)+",以后你就是参将了！\n",ob);
			me->set("guanzhi","canjiang");
			return 1;
		}
		else if(me->query("guanzhi")=="canjiang")
			 return notify_fail("你还是再为朝廷出些力气吧！\n");
	if(score<900000)
		if(me->query("guanzhi")=="shibing"||me->query("guanzhi")=="xiaowei"
			||me->query("guanzhi")=="canjiang")
		{
			message_vision("$N笑道：好啊，"+RANK_D->query_respect(me)+",以后你就是官差了！\n",ob);
			me->set("guanzhi","guanchai");
			return 1;
		}
		else if(me->query("guanzhi")=="guanchai")
			 return notify_fail("你还是再为朝廷出些力气吧！\n");
	if(score<2000000)
		if(me->query("guanzhi")=="shibing"||me->query("guanzhi")=="xiaowei"
			||me->query("guanzhi")=="canjiang"
			||me->query("guanzhi")=="guanchai")
		{
			message_vision("$N笑道：好啊，"+RANK_D->query_respect(me)+",以后你就是武将了！\n",ob);
			me->set("guanzhi","wujiang");
			return 1;
		}
		else if(me->query("guanzhi")=="wujiang")
			 return notify_fail("你还是再为朝廷出些力气吧！\n");
    if(me->query("guanzhi")=="jiangjun")
		return notify_fail("你已经不能再升官了！想造反吗！？\n");
	message_vision("$N笑道：好啊，"+RANK_D->query_respect(me)+",以后你就是将军了！\n",ob);
			me->set("guanzhi","jiangjun");
			return 1;
}

int do_fenglu()
{
	object me,ob;object gold;
	me=this_player();
	ob=this_object();
	if(me->query("shili")!=ob->query("shili"))
		return notify_fail("你不是我们的人，我怎么给你俸禄？\n");
	if(me->query("guanzhi")=="shibing")
		return notify_fail("很遗憾，士兵是没有俸禄的。\n");
    if(time()-me->query("fenglu_time")<3600)
		return notify_fail("你一个月后在来领取俸禄吧！\n");
    gold=new("/clone/money/gold");
	if(me->query("guanzhi")=="xiaowei") gold->set_amount(5);
	else if(me->query("guanzhi")=="canjiang") gold->set_amount(15);
	else if(me->query("guanzhi")=="guanchai") gold->set_amount(35);
	else if(me->query("guanzhi")=="wujiang") gold->set_amount(60);
  	else if(me->query("guanzhi")=="jiangjun") gold->set_amount(100);
    else return notify_fail("你没当官，领什么俸禄？\n");
	me->set("fenglu_time",time());
	gold->move(me);
	tell_object(me,"你拿到了俸禄。\n");
	return 1;
}