
#include <ansi.h>
inherit ROOM;
int do_lingwu(string arg);
void create ()
{
  set ("short",HIB"天魔堂"NOR);
  set ("long", @LONG
这里是阴癸派的天魔堂，在这里你可以领悟[lingwu]阴癸派
的内功心法--天魔大法。这里静悄悄的，旁边有几个弟子正在盘
膝而做，面色沉静，你不禁放轻了脚步。
LONG);

  set("exits", ([ 
 "out":"/d/yinkui/woshi2",
        ]));
  set("no_channel","领悟中还是不要说话了\n");
  set("no_tell","领悟中还是不要说话了\n");
  set("valid_startroom", 1);
  set("force","tianmo-dafa");
  setup();
 
}
void init()
{
   add_action("do_lingwu","lingwu");
}
#include "/d/clone/room/lingwu/lingwu.c"
