
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","石路");
  set ("long", @LONG
这里是大雄宝殿后的石路。东面是禅院的禁地，平时不准别人进去
的。诵经声就在铜殿之后相隔只有十丈许的大殿传出，寺内其他地方则
不见半个人影，有种高深莫测，教人不敢轻举妄动的情景。
LONG);

  set("exits", ([ 
	  "westup":__DIR__"daxiong-baodian",
	  "enter":__DIR__"tongdian",
  
         ]));
 
set("outdoors","chanyuan");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
	if(dir=="east"&&(objectp(present("bu chi",environment(me)))||objectp(present("bu ju",environment(me))))&&!wizardp(me)
	   &&me->query("family/family_name")!="静念禅院")
		return notify_fail("只听一声洪亮的声音说道：施主请留步!\n");
	return ::valid_leave(me,dir);
}

