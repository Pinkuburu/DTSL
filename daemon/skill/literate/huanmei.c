//媚功幻术
//幻媚

#include <ansi.h>
#include <skill.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int ap,vp;
	
	if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
        
	if(target==me)
			return notify_fail("「媚功幻术」只能用来攻击别人！\n");
	if(me->query("gender")!="女性")
	return notify_fail("只有女人能使用媚功幻术去迷惑敌人！\n");
	if(me->query("age")>60)
	return notify_fail("你的年龄太大了，谁会受你迷惑？\n");
	if(target->query("gender")=="女性")
	return notify_fail("对方也是女人，使用媚功幻术不会有任何效果！\n");
	if(!me->is_fighting())
	return notify_fail("「媚功幻术」只能在战斗中使用！\n");
	if(!living(target))
		return notify_fail("你先把对方弄醒在迷惑对方吧！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	if(!me->query_skill("meigong-huanshu",1))
		return notify_fail("不学媚功幻术如何使用「幻媚」？\n");
	if((int)me->query_skill("meigong-huanshu",1)<110)
		return notify_fail("你的媚功幻术修为不够！\n");

        if(time()-me->query_temp("exert_busy/huanmei")<15)
        return notify_fail("你真气不足，无法施展「幻媚」！\n");
        
        ap=me->query_skill("meigong-huanshu",1)/10;
        ap=ap*me->query_per()/(me->query_per()+60);
        
        vp=me->query_skill("chanzong-fofa",1)/10;
        vp=vp*me->query_per()/(me->query_per()+40);
        
        if(vp<=0) vp=random(ap/2);
        
        if(target->query("class")=="bonze")
        vp=vp*2;
        
        if(random(ap+vp)>vp){
          msg=HIY"\n$N"+HIY+"忽地轻呼道：“唉，"+RANK_D->query_self(me)+"累了！”就地坐了下来，春意盈盈的美目柔情\n"+
              "似水地瞧着$n"+HIY+"。 $N"+HIY+"那动人的体态和脸上正闪着的贞洁的光辉形成这极端\n"+
              "的对比，更使人兴起不顾一切，粉碎你端庄严正外表的意欲。\n"NOR;
          message_vision(msg,me,target);
          
          msg="\n$N斗志全消，只觉得斗争仇杀，你争我夺，全是绝无意义的一回事，竟然\n"+
              "忘记自己在战斗中。\n";
          message_vision(msg,target);
          
          target->start_busy(3);
          target->set("apply_points",0);
          me->set_temp("perform_busy",time());
          me->set_temp("exert_busy/huanmei",time());
          return 1;
        }
        
        msg=HIY"\n$N"+HIY+"面容恬静下来，垂下美目，轻叹了一口气。 把娇嫩的纤手递给$n"+HIY+"，撒\n"+
            "娇似的道：“"+RANK_D->query_respect(target)+"可拖人家起来吗？” \n"NOR;
        message_vision(msg,me,target);
        msg="\n$n卓立不动，目无表情地低头看着$N，仿佛$N只是件没有生命的死物。\n"+ 
            "$N浑身不自在起来，$N的眼神感到心内所有秘密都完全暴露了出来。\n";
        message_vision(msg,me,target);
        me->start_busy(1);
        me->set_temp("perform_busy",time());
        me->set_temp("exert_busy/huanmei",time());
        return 1;
}

