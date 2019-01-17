
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIW"静思堂"NOR);
  set ("long", @LONG
这里是慈航静斋的静思堂。这里没有什么摆设，只有几个软
蒲团。正面有一个菩萨的塑像，还有几柱刚刚上好的香。你
可以在这里领悟[lingwu]慈航静斋的内功心法--清心普善诀。
LONG);

  set("exits", ([ 
 "out":__DIR__"mishi2",
        ]));
  set("no_channel","领悟中还是不要说话了\n");
  set("no_tell","领悟中还是不要说话了\n");
  set("valid_startroom", 1);
  set("force","qingxin-force");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"