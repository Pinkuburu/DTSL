
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"海滩"NOR);
	set("long", @LONG
这里是海滩。一阵海风吹得你衣衫凌乱。南边有一片树林。不时从
树林出蹦出一两只野兔，然后又迅速地跑开。
LONG);
	set("exits", ([
		"west":__DIR__"haitan1",
                "north":"/d/quest/dmchuifa/haitan",
		"southeast":__DIR__"shulin2",
		
	]));
	set("objects",([
	  __DIR__"npc/haigui":1,
	  ]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

