//Edit By Subzero
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIY"贪狼吞"NOR, ({ "tanlang tun","tanlang","dao" }) );
   set_weight(80000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("no_save",1);
     set("rumor",1);
     set("super",5);
     set("value", 100000000);
     set("material", "iron");
     set("no_sell", 1);
     set("long", HIY"此刀历史久远，相传在秦末战乱中诞生，已无人能知其是何人何时打造\n"+
                    "而成，唯一得知的，就是此刀连鞘皆由玄铁铸造，重达一百五十斤！刀\n"+
                    "身排列整齐横纹，虽无锋刃，但是注入内家高手的真气后，刀身自然产\n"+
                    "生一层气刃，一般宝刃亦不能与之抗衡。\n"NOR);
     set("wield_msg", HIR"$N"+HIR+"探手一按刀鞘，“铮”的一声，$n"+HIR+"像活过来般发出吟音，\n"+
                         "竟从鞘子内跳出来，和给人手握刀柄拔出来全无分别，看得周围人心中直冒寒气。\n"NOR);
     set("unequip_msg",HIB"$N"+HIB+"隔空虚抓，$n"+HIB+"若如给一条无形的绳索牵扯般，\n落入他左手掌握的刀鞘中。\n"NOR);
   }
   init_blade(130,200,200);
   setup();
}
