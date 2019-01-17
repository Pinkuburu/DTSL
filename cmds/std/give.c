// give.c

inherit F_CLEAN_UP;

int do_give(object me, object obj, object who);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要给谁什麽东西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什麽东西？\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
		if( obj->query("no_drop")||obj->query("no_give") )
			return notify_fail("这样东西不能随便给人。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那麽多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_give(me, obj2, who);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	if( obj->query("nogive_player")&&userp(who) )
	return notify_fail("这样东西不能在玩家之间进行交换。\n");
       if(obj->query("no_give"))
		return notify_fail("这样东西不能随便给人。\n");
        notify_fail("对方不要你的东西。\n");
	if( !interactive(who) && !who->accept_object(me, obj) )
	  /*   if((int)who->accept_object(me, obj)==0)
	     return notify_fail("你只能把东西送给其他玩家操纵的人物。\n");
	     else*/ 
	     return (int)who->accept_object(me, obj);
	      
        if(who->query("env/no_accept")&&wiz_level(me)<=wiz_level(who))
        return notify_fail("对方拒绝接受物品。\n");
//	if( !userp(who) && obj->value() ) {
      if( !userp(who) && !userp(obj)&&!who->query("can_carry") ) {
		tell_object(me,"你拿出" + obj->short() + "给" + who->name()+"。\n");
		destruct(obj);
		return 1;
	} else if( obj->move(who) ) {
		printf("你给%s一%s%s。\n", who->name(), obj->query("unit"),
			obj->name());
		message("vision", sprintf("%s给你一%s%s。\n", me->name(),
			obj->query("unit"), obj->name()), who );
//		message("vision", sprintf("%s给%s一%s%s。\n", me->name(), who->name(),
//			obj->query("unit"), obj->name()), environment(me), ({me, who}) );
		me->save();
	   log_file( "GIVE_LOG", sprintf("(%s)
%s give %s to %s\n", ctime(time()), me->query("id"), obj->query("name"), 
		who->query("id")));
		return 1;
	}
	else return 0;
}
int help(object me)
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>
 
这个指令可以让你将某样物品给别人, 当然, 首先你要拥有这样物品.
 
HELP
    );
    return 1;
}
