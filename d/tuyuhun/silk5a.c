// /d/xingxiu/silk5a.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", BRED"胭脂山"NOR);
        set("long", @LONG
胭脂山因山石赭红似胭脂而得名。这里水草丰美，宜于畜牧。冰雪
融化，清流缓缓而下，汇集成渠。山下绿草如茵的马营草场滩，是久负
盛名的牧场。
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "eastdown" : __DIR__"silk4",
                "northwest" : __DIR__"silk7a",
        ]));

        setup();
        set("yushi_count", 1);
}
