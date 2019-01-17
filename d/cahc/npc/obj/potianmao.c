//Edit By Subzero
#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIR"破天矛"NOR,({ "potian mao", "mao", "spear" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("value", 5000000);
                set("material", "steel");
                set("rumor", 1);
                set("no_sell", 1);
                set("super", 4);
                set("weapon_prop/parry", 2);
                set("weapon_prop/dodge", -5);
                set("wield_maxforce", 800);
                set("wield_str", 23);
                set("long", HIR"此矛乃关中“矛妖”颜平照之物，由精钢打造而成，重七十五斤，坚硬锐利，
后传与其子颜历。矛身浮雕五彩祥云，固有破天之称。\n");
                set("wield_msg", WHT"$N"+WHT+"仰天长啸，尽展豪迈之气，伸手从背后抽出$n"+WHT+"，舞出一片矛影，更添威势。\n"NOR);
                set("unwield_msg", HIY "$N"+HIY+"将矛抛向空中，随即跃起，在空中探手抓住$n"+HIY+"，插回后背背囊，潇洒落地。\n" NOR);                
        }
   init_spear(120,180,180);
        setup();
}
