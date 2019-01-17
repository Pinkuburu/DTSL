
int exert(object me, object target)
{
	int n, q;

	if (me != target)
		return notify_fail("你只能用内功调匀自己的气息。\n");
    if(me->is_busy()) return notify_fail("你正忙着呢!\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够。\n");

    if(me->query("kee")==me->query("eff_kee"))
		return notify_fail("你现在气力充沛。\n");
	q=(int)me->query("eff_kee",1)-(int)me->query("kee",1);
	n=(int)me->query("force",1);
	if(n>=q)
	{
		me->add("force",-q);
		me->set("kee",(int)me->query("eff_kee",1));
		message_vision("$N深深吸了几口气,精神看起来好多了.\n",me);
	}
	else
	{
		me->add("force",-(n-10));
		me->add("kee",n-10);
		message_vision("$N深深吸了几口气,虽感内力不足,但精神看起来也好多了.\n",me);
	}
	if(me->is_fighting()) me->start_busy(1);
	
	
	return 1;
}
