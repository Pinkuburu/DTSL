// /d/gaoli/xiaojiuguan
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "小酒馆");
	set("long", @LONG
酒馆不大，屋中零乱的摆了几张方桌，几条长凳。小柜台上摆了些
酒坛，所卖也不过是些花生米，老白干之类。但这的白干后劲大，所以
这的酒客却不少。
LONG
	);
set("exits", ([
                "west" : __DIR__"nandajie",       
	]));
   set("objects",([
      __DIR__"npc/wang":1,
      ]));
       setup();
	replace_program(ROOM);
}	
