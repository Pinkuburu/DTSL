
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"matou"
#define TO __DIR__"huafang"
#include "/std/shiproom.c";
void create ()
{
  set ("short","码头");
  set ("long", @LONG
这里是瘦西湖的码头，有很多澄徒浪子在这里搭船去画舫寻花问柳
一个个看起来都不是什么好东西。
LONG);

  set("exits", ([ 
  "northeast":__DIR__"guangchang1",
         ]));

  set("valid_startroom", 1);
  set("outdoors","yangzhou");
  setup();
 
}


int valid_leave(object me,string dir)
{
	if(dir=="northeast")
		me->delete_temp("gived_money");
	return ::valid_leave(me,dir);
}