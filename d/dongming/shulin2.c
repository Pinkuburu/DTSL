
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"树林"NOR);
	set("long", @LONG
这里是一片茂密的树林。南边有一个山崖。这里冷冷清清，几乎没
有什么人来这里。
LONG);
	set("exits", ([
		"northwest":__DIR__"haitan2",
                "south":"/d/clone/room/lingwu/dongming/shanya",
		"east":__DIR__"pubu",
	]));
	set("objects",([
		__DIR__"npc/shangwannian":1,
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

