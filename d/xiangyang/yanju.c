
#include <ansi.h>
inherit ROOM;

#define JOBNAME "襄阳"

void create ()
{
  set ("short","盐局");
  set ("long", @LONG
这里是襄阳的盐局，总管襄阳的盐运。但是由于战乱，民间贩卖私
盐的事情屡禁不止，所以盐局的生意并不是很好。进来官府征召一些人
力来运盐，但是还要防止有人半路抢劫盐车，所以来应召的大部分都是
武林中的人物。只见一个盐局的官差威风凛凛地站在那里，不时有人从
他那里领走盐车朝外走去。
LONG);

  set("exits", ([ 
 "south":__DIR__"xidajie1",
       ]));
  set("objects",([
	  "/d/job/yunyanjob/guanchai":1,
	  ]));
  set("job_name",JOBNAME);
  set("valid_startroom", 1);
  setup();
 
}

