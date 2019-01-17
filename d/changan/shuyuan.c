
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","书院");
  set ("long", @LONG
这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐
在太师椅上讲学，那就是当今大儒夏先生了。在他的两侧坐满了求学的
学生。一张古意盎然的书案放在夏先生的前面，案上摆着几本翻开了的
线装书籍。
LONG);

  set("exits", ([ 
 "west":__DIR__"zqdajie3",
       ]));
  set("objects",([
	  __DIR__"npc/xia":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

