
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"卧室"NOR);
	set("long", @LONG
这里是东溟夫人的卧室。床上被褥叠得整整齐齐。里边放着一个梳
妆台，旁边的墙上挂着一柄长剑。窗户敞开着，外面是一片竹林，一片
碧绿，看起来赏心悦目。这里很干净，看起来刚刚打扫过。
LONG);
	set("exits", ([
		"out":__DIR__"qingzhugong",
	]));
  set("objects",([
	  __DIR__"npc/shanmeixian":1,
	  ]));
        
       set("valid_startroom", 1);   
	setup();
       
       
}

     
