

inherit F_CLEAN_UP;
#include <poison.h>
int do_drink(object me,object ob);
int main(object me, string arg)
{
   object where;object ob;
   where=environment(me);
   if(me->is_fighting())
	   return notify_fail("你还是先打完仗吧！\n");
   if(!arg){
   if(!where->query("resource/water"))
     return notify_fail("这地方没有水可喝！\n");
   if(me->query("water")>=me->max_water_capacity())
	   return notify_fail("你喝得太多了，已经喝不下了！\n");
   if(me->is_busy())
	   return notify_fail("你正忙着呢！\n");
   message_vision("$N喝了几口水，觉得好多了。\n",me);
   me->add("water",me->query_con()*2);
   POISON_D->apply_poison(me,where);
   me->start_busy(1);
   }
   else {
   	if(me->query("water")>=me->max_water_capacity())
	   return notify_fail("你喝得太多了，已经喝不下了！\n");
	   if(!objectp(ob=present(arg,me)))
		   return notify_fail("你身上没有这种东西！\n");
	   if(!ob->query("liquid"))
	   return notify_fail("这种东西不能喝水！\n");
	   me->start_busy(1);
	   return (int)do_drink(me,ob);
	   
   }
   return 1;
}
int do_drink(object me,object ob)
{
	int remain,avai;	
        if(ob->query("liquid/remaining")<=0 )
                return notify_fail( ob->name() + (ob->query("liquid/name") ? 
"已经被喝得一滴也不剩了。\n":"是空的。\n"));
	remain =(int)ob->query("liquid/remaining") * 30;
	avai = me->max_water_capacity() - me->query("water");
	if( remain > avai )
	{
	me->add("water", avai);	
	ob->add("liquid/remaining", -(avai/30));
	}
	else
	{
	me->add("water",remain);
	ob->set("liquid/remaining", 0);
	}
        message_vision("$N拿起" + ob->name() + "咕噜噜地喝了几口" + 
ob->query("liquid/name")
                + "。\n", me);
       if( !ob->query("liquid/remaining") )
                write("你已经将" + ob->name() + "里的" + ob->query("liquid/name")
                        + "喝得一滴也不剩了。\n");

        // This allows customization of drinking effect.
        if( ob->query("liquid/drink_func") ) return 1;
        POISON_D->apply_poison(me,ob);
        switch(ob->query("liquid/type")) {
                case "alcohol":
                        me->apply_condition("drunk",
                                me->query_condition("drunk") 
                                + (int)ob->query("liquid/drunk_apply"));
                        break;
        }
        
        return 1;
}