// xuantiejian 玄铁剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( HIB"玄铁剑"NOR,({ "xuantie jian", "xuantie", "jian", "sword"}) );
        set_weight(35000);
        if( clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 1);
                set("unique", 1);                
                set("rigidity", 10);
                set("sharpness", 9);
                set("material", "steel");
                set("weapon_prop/parry", 10);
                set("treasure",1);
                set("wield_neili", 1200);
                set("wield_maxneili", 1500);
                set("wield_str", 35);
                set("wield_msg", HIB"$N嗡的一声从背后抽出玄铁剑，但见寒气逼人，方圆之内轰然雷声滚滚，肃杀万分。\n"NOR);
                set("long", "此剑长七尺，由万年玄铁所铸，沉重无比，无锋无刃，却杀气森然，实乃天下第一神兵。\n");                
                set("unwield_msg", HIB "$N将玄铁剑插回肩后，杀气顿减。\n" NOR);               
        }
        init_sword(200);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "xuantie-jianfa" ||
            me->query_skill("xuantie-jianfa", 1) < 100)
                return damage_bonus / 2;

        switch (random(6))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 200 + 1);
                return HIB "玄铁剑幻突然发出一股劲气,$n只觉得胸口一闷，真气竟提不上来。\n"NOR;



        case 1:
                n = me->query_skill("sword");
                victim->receive_damage("qi", n , me);
                victim->receive_wound("qi", n , me);
                victim->receive_damage("jing", n/5 , me);
                victim->receive_wound("jing", n / 5, me);
                 victim->receive_wound("neili", n *2, me);

                return BLU"玄铁剑带起一道凌厉的劲风，只听砰的一声巨响，$n象断了线的风筝一般飞了出去。\n" NOR;


        }
        return damage_bonus;
}

