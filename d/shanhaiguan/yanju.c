
#include <ansi.h>
inherit ROOM;

#define JOBNAME "山海关"

void create ()
{
  set ("short","盐局");
  set ("long", @LONG
这里是山海关的盐局，总管山海关的盐运。但是由于战乱，民间贩
卖私盐的事情屡禁不止，所以盐局的生意并不是很好。进来官府征召一
些人力来运盐，但是还要防止有人半路抢劫盐车，所以来应召的大部分
都是武林中的人物。只见一个盐局的官差威风凛凛地站在那里，不时有
人从他那里领走盐车朝外走去。
LONG);

  set("exits", ([ 
 "south":__DIR__"dongdajie",
       ]));
  set("objects",([
	  "/d/job/yunyanjob/guanchai":1,
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

