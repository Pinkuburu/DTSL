// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object where = environment(me);
        object ob;int sum;string ob_name;
        string zhao_name;
        mapping skill;
        int my_skill, cost;

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if (where->query("sleep_room"))
                return notify_fail("卧室不能读书，会影响别人休息。\n");

        if( me->is_fighting() )
                return notify_fail("你无法在战斗中专心下来研读新知！\n");
        if(!arg||(sscanf(arg,"%s",ob_name)!=1&&
           sscanf(arg,"%s for %d",ob_name,sum)!=2))
        return notify_fail("请使用 study|du <书名> 或study|du <书名> for <次数>\n");
        if(sscanf(arg,"%s for %d",ob_name,sum)!=2) sum=1;
        if(sum>100)
        return notify_fail("读书还是慢慢来吧！\n");
        if(sum<=0)
        return notify_fail("专心读书，不要捣乱。\n");
        if(!objectp(ob = present(ob_name, me)) )
                return notify_fail("你要读什么？\n");
       if( !mapp(skill = ob->query("skill")) )
                return notify_fail("你无法从这样东西学到任何东西。\n");

        if( !me->query_skill("literate", 1) )
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
        if(me->query("gin")<10*sum)
			return notify_fail("你太累了，休息一下吧！\n");
        if (!random(5))
                message("vision", me->name() + "正专心地研读" + ob->name()
                + "。\n", environment(me), me);

        if( (int)me->query("combat_exp") < skill["exp_required"])
                return notify_fail("你的实战经验不足，再怎么读也没用。\n");
               
        if( me->query_int() < skill["difficulty"])
              return notify_fail("以你目前的领悟能力，还没有办法学这个技能。\n");
        notify_fail("以你目前的能力，还没有办法学这个技能。\n");
        
        if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

        cost = (skill["jing_cost"] + skill["jing_cost"] 
                * (skill["difficulty"] - (int)me->query("int"))/20)*sum;
        if (cost < 10) cost = 10*sum; // minimum cost
        if(me->query("gin")<cost) return notify_fail("你的精力不足了，歇歇吧！\n");
        if( me->query_skill(skill["name"], 1) < skill["min_skill"] )
                return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太深了，没有学到任何东西。\n");
        if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
                return notify_fail("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");

        if( !me->query_skill(skill["name"], 1) ) me->set_skill(skill["name"], 0);

        my_skill = me->query_skill(skill["name"], 1);

        if( (int)me->query("gin") > cost ) {
                if(SKILL_D(skill["name"])->query_type()!="knowledge"
                &&SKILL_D(skill["name"])->query_type()!="literate"
                &&      my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
                        write("也许是缺乏实战经验，你对"+ob->name()+"上面所说的东西总是无法领会。\n");
                } else {
                        write(sprintf("你研读有关%s的技巧，似乎有点心得。\n", to_chinese(skill["name"])));
                        me->improve_skill(skill["name"], sum*((int)me->query_skill("literate", 1)/5+me->query_int()/4+1));
                }
        } else {
                cost = me->query("gin");
                write("你现在过于疲倦，无法专心下来研读新知。\n");
                return 1;
        }

       if (cost < 1) cost = 1;
        me->receive_damage("gin", cost );

        return 1;
}

int help(object me)
{
   write( @HELP
指令格式: study|du <物品名称>或 study|du <物品名称> for <次数>

这个指令使你可以通过阅读秘笈或其他物品自学某些技巧,
但前提是: 你不能是个『文盲』。

see also : learn
HELP
   );
   return 1;
}
