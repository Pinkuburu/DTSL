// xiupao.c
// Lklv 2001.9.25

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIY"锦缎绣袍"NOR, ({ "xiu pao", "xiupao", "pao" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("long", HIY"一件黄缎子绣袍，颜色十分好看。\n"NOR);
                set("value", 8500);
                set("armor_prop/armor", 2);
        }
        setup();
}