
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","月老亭");
  set ("long", @LONG
这里是扬州的月老亭。亭口的正上方挂着一个大红花，两旁垂下来
几幅彩带。亭子的上方四周还挂着一圈的彩带，上面绣着龙凤呈祥。许
多武林中情投意合的男女都在这里找月老来成全他们的婚姻。
LONG);

  set("exits", ([ 
 "north":__DIR__"dongdajie2",
        ]));
  set("objects",([
 "/d/clone/npc/yuelao":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

