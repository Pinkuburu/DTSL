
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","太极殿");
  set ("long", @LONG
这里就是大唐的金鸾宝殿，朝政要事全是在这里处理。殿内陈设华
丽，镌镂龙凤飞镶之状，雄伟壮丽，金壁生辉。室内外梁枋上饰以和玺
彩画。门窗上部嵌成菱花格纹，下部浮雕云龙图案，接榫处安有镌刻龙
纹的鎏金铜叶。殿内金砖铺地，明间设宝座，上坐着大唐当今天子李渊。 
LONG);

  set("exits", ([ 
 "north":__DIR__"liangyidian",
 "southdown":__DIR__"taijimen",
        ]));
  set("objects",([
          "/d/changan/npc/liyuan":1,
          "/d/cahc/npc/wei":1,
          ]));

   set("valid_startroom", 1);
  setup();
 
}

