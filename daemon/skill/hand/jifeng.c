//风雪八腿
//疾风暴雪
#include <ansi.h>

inherit SSERVER;

#define REDUCE_DEX -50

int perform(object me,object target)
{ 
   object weapon;
   string msg;
   int damage;
   
    weapon=me->query_temp("weapon");
    if(!target)
    if(!objectp(target=offensive_target(me)))
    return notify_fail("目前你没有攻击的目标！\n");
	if(!me->is_fighting())
		return notify_fail("「疾风暴雪」只能在战斗中使用!\n");
   if(weapon)
    return notify_fail("拿着武器，如何使用「疾风暴雪」？\n");
    if(!me->query_skill("fengxue-leg",1))
    return notify_fail("不学「风雪八腿」如何使用「疾风暴雪」？\n");
    if((int)me->query("max_force")<1000)
    return notify_fail("你的内力太低了!\n");
    if((int)me->query_skill("leg",1)<110)
    return notify_fail("你的基本腿法太差了！\n");
    if((int)me->query_skill("fengxue-leg",1)<110)
    return notify_fail("你的「风雪八腿」还不到家！\n");
    if((int)me->query_skill("jiuxuan-dafa",1)<100)
    return notify_fail("你的「九玄大法」还不到家！\n");
    if(me->query("apply_points")<=0)
    return notify_fail("凭你目前的气势无法施展「疾风暴雪」！\n");
    if(time()-me->query_temp("perform_busy")<5)
      return notify_fail("连续施展「疾风暴雪」需要深厚的先天真气支持，你修为不够，如何能行？\n");
    
    damage=me->query("apply_points")/2;
    
    msg=HIG"$N"+HIG+"悠闲自得的一脚往$n"+HIG+"踹来，$n"+HIG+"的心神完全被$N"+HIG+"这一脚吸引过去至乎忘了身在何处，\n"+
        "这看似平平无奇的一脚发出的气势劲道，如风似雪，把$n"+HIG+"的感官完全笼罩其中，连肌肤\n"+
        "也如被针刺！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「疾风暴雪」只能在战斗中使用!\n");
    
    msg=HIY"$N"+HIY+"露出哑然失笑的神色，冲天而起,卓立虚空，看似漫不经意的飘身下降，同时脚尖下\n"+
        "点，踢向$n"+HIY+"的$l。蓦地$N"+HIY+"凭着足点之力，陀螺般急旋起来，缓缓升起，情况怪\n"+
        "异到极点！\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
    if(!me->is_fighting())
    return notify_fail("「疾风暴雪」只能在战斗中使用!\n");
    
    msg=WHT"$N"+WHT+"身躯一颤，忽然幽灵般飘起，动作似缓实快，倏忽间现身于$n"+WHT+"身边，双腿似连环踢向\n"+
        "$n"+WHT+"脸门，招数狠辣迅快，令$n"+WHT+"防不胜防。$N"+WHT+"脚速骤增，令人难以置信的变招，\n"+
        "疾取$n"+WHT+"腹下气海的重要部位。\n"NOR;
    
    COMBAT_D->do_perform_attack(damage,REDUCE_DEX,msg,me,target,0,0,2);
    
        me->set_temp("perform_busy",time());
    return 1;   
  
}  
 
