

int exert(object me, object target)
{
		int n,q;
	if (target != me) 
		return notify_fail("你只能用内功恢复自己的精力。\n");
	if(me->is_busy()) return notify_fail("你正忙着呢!\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够。\n");

if(me->query("gin")==me->query("eff_gin"))
		return notify_fail("你现在精力充沛。\n");
	q=(int)me->query("eff_gin",1)-(int)me->query("gin",1);
	n=(int)me->query("force",1);
	if(n>=q)
	{
		me->add("force",-q);
		me->set("gin",(int)me->query("eff_gin",1));
		message_vision("$N深深吸了几口气,精神看起来好多了.\n",me);
	}
	else
	{
		me->add("force",-(n-10));
		me->add("gin",n-10);
		message_vision("$N深深吸了几口气,虽感内力不足,但精神看起来也好多了.\n",me);
	}
	if(me->is_fighting()) me->start_busy(1);
	return 1;
}

