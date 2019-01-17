
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIB"暗室"NOR);
	set("long", @LONG
这里是一个暗室，四周黑洞洞的，看起来错综复杂，似乎很容易迷
路。
LONG);
        set("exits",([
          "east":__DIR__"migong10",
          "west":__DIR__"migong9",
          "south":__DIR__"migong8",
          "north":__DIR__"migong7",
          "out":__DIR__"xiaoxi",
          ]));
	setup();      
}

int valid_leave(object ob,string dir)
{
  if(ob->query_temp("dtsl_quest_csj_action1")&&dir=="out"){
    ob->delete_temp("dtsl_quest_csj_action1");
    ob->set_temp("dtsl_quest_csj_action2",1);
  }
  return ::valid_leave(ob,dir);
}
