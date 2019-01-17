// Room: /d/xingxiu/silk3c.c
// Jay 3.17/96
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", WHT"月牙泉"NOR);
        set("long", @LONG
出乎你的意料之外，在沙漠中竟然有一汪月牙形的泉水，涟漪萦回，
水草丛生，清澈见底。这里出产铁背鱼、七星草，但不常见。此泉虽在流
沙山群中，风起沙飞，均绕泉而过，从不落入泉内。北面是一片峭壁，东
边传来嗡嗡的声响。
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "west" : __DIR__"silk7a",
                "east" : __DIR__"silk3b",
        ]));

        setup();
}
