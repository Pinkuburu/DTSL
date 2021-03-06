//last modify by mudadm

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dir;
	object ob, *guards;
	mixed old_target;

        if( ( me->is_busy() || me->is_fighting()
           || me->query_temp("guardfor")) && arg
           && arg != "none" )
		return notify_fail("你现在没有办法分心去做这类事！\n");
        if(me->query("pker"))
        return notify_fail("作为通缉犯还是老实一些吧！\n");
	old_target = me->query_temp("guardfor");

	if( !arg || arg=="" ) {
		if( !old_target )
                        return notify_fail("指令格式：guard <生物>|<物品>\n");
		if( objectp(old_target) )
			if( living(old_target) )
				write("你正在守护著" + old_target->name() + "。\n");
			else
				write("你正守在" + old_target->name() + "一旁，防止别人拿走。\n");
		return 1;
	}

	ob = present(arg, environment(me));

	if( ob ) {
		if( ob==me ) return notify_fail("守卫自己？不用说你也会做，对吧。\n");
		if(ob->query("pker"))
		return notify_fail("任何人不能保护通缉犯！\n");
		me->set_temp("guardfor", ob);
	}

        else if( arg!= "none" )
                return notify_fail("你要守卫谁，什麽？\n");

        if( objectp(old_target) ) {
		guards = old_target->query_temp("guarded");
		guards -= ({ me });
		old_target->set_temp("guarded", guards);
        }  


        if( arg=="none" ) {

	if( objectp(old_target) ) {

       tell_object( old_target, me->name() + "不再保护你了。\n");
       tell_object(me,"你决定不在保护"+old_target->name()+"了！\n");
       me->delete_temp("guardfor");
       old_target->reduce_temp_array("guarded",me);
       me->set_leader(0);
       write("Ok.\n");
       return 1;
	}
       else
    {
       tell_object(me,"你决定不再保护别人。\n");
       me->delete_temp("guardfor");
       me->set_leader(0);
       write("Ok.\n");
       return 1;
    }
 }
	if( objectp(ob) ) {

                ob->add_temp("guarded", ({ me }) );
		if( living(ob) )
                    {
                       message_vision("$N开始保护$n。\n", me, ob);
                       me->set_leader(ob);
                    }
		else
                       message_vision("$N站到地上的$n一旁守著，以免别人取走。\n", me, ob);
	return 1;
}
}
int help(object me)
{
	write(@TEXT
指令格式：guard [<某人>|<地上某物>|none]

这个指令有两种作用方式，分别如後：

guard <某人>      保护<某人>，当他／她受到攻击时，保护者会自动加入战斗，并且
                  受攻击的顺位会排在被保护者前面，由於只有攻击顺位前四个目标
                  才会受到攻击，因此理论上如果有四个人  guard 你，你就不会受
                  到任何攻击。

guard <地上某物>  守住放在地上的某件东西，防止别人来拿，只要你还在这个房间，
                  而且没有忙著其他事，别人就无法拿走这件东西。

guard none        取消先前的 guard 对象。
guard             不接任何参数会显示你目前 guard 的对象。

注意，通常除了 guard <某人> 的情形以外，只要你一移动，guard 的状态就会解除。
另外通缉犯是无法保护他人的。
TEXT
	);
	return 1;
}
