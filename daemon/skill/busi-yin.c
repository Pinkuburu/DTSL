//不死印。


inherit SKILL;
#include <ansi.h>

string *actions=({
HIB"$N"+HIB+"身形如同鬼魅般地晃动了几下，如流星一般躲开了$n"+HIB+"的攻击！\n"NOR,
HIB"$N"+HIB+"身形微微晃动，脚步几个旋转，躲开了$n"+HIB+"的攻击！\n"NOR,
HIB"$N"+HIB+"脚踏玄步，猛一吸气，胸口陷进数寸，闪开了$n"+HIB+"的攻击！\n"NOR,
HIB"$N"+HIB+"内力一阵鼓荡，形成一个无影的墙壁，挡开了$n"+HIB+"的攻击！\n"NOR,
HIB"$N"+HIB+"运气数息，口中默念不死印诀，只见一鼓气劲挡住了$n"+HIB+"的攻击！\n"NOR,
});
string query_type()
{
  return "knowledge";
}

int valid_learn(object me)
{
        if((int)me->query_skill("busi-yin",1) > 400 )
            return notify_fail("单纯的学习已经无法让你从本质上提高了，自己去领悟精髓吧。 \n");
  
  if(!me->query("execute_quest/busiyin",1))
   return notify_fail("你现在无法领会不死印的奥秘！\n");
  
  return 1;
  
}

string *query_execute()
{
   return ({"yin","shengsi"});
}

