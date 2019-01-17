
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",GRN"王府内厅"NOR);
  set ("long", @LONG
这里是王府的内厅。正厅的前面挂一副画，仔细辨认可以知道是名
家的大作。大厅的两旁有几个侍卫守护在这里，目光威严。有几个丫鬟
在那里擦拭着桌椅。平时很少有人来这里的。
LONG);

  set("exits", ([ 

  "out":__DIR__"wangfu",
  "east":__DIR__"zoulang1",
  "west":__DIR__"zoulang2",
       ]));
  
  set("objects",([
	  __DIR__"npc/shiwei":2,
"/d/job/yangkilljob/yanggong-qing":1,
	  ]));
 set("no_fight",1); set("no_exert",1);
  
  set("valid_startroom", 1);
  setup();
 
}

/*int valid_leave(object me,string dir)
{
	if(objectp(present("shi wei",environment(me)))&&dir=="east"&&!wizardp(me))
		return notify_fail("侍卫喊道:里面是王大人的卧室,不可随便进入!\n");
	return ::valid_leave(me,dir);
}*/
