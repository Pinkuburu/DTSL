#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","药房");
  set ("long", @LONG
这里药师工会的药房，里面有一个很大的炼药鼎，一个药师正在炼
制着各种的丹药，旁边有一排药柜，你闻到从药柜里面传出来一阵浓烈
的药香。
LONG);

  set("exits", ([ 
 "west":__DIR__"yaoshigh",
       ]));
  set("objects",([
	  "/d/job/yishengjob/yisheng2":1,
	  "/d/job/yishengjob/ding":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

