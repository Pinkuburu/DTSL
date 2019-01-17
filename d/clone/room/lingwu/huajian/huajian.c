
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIB"密室"NOR);
  set ("long", @LONG
这里是一个密室，四周黑漆漆的。墙上隐约可以看见有几行
字。这里可以领悟「lingwu」花间的内功心法--飞花流水。这里
非常寂静，你的心中渐渐平静下来了。
LONG);

  set("exits", ([ 
 "out":"/d/changan/didao3",
        ]));
  set("no_channel","领悟中还是不要说话了\n");
  set("no_tell","领悟中还是不要说话了\n");
  set("valid_startroom", 1);
  set("force","flower-force");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
