
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","北天街");
  set ("long", @long
这里是北天街。这里的人异常的多。西边是洛阳最大的青楼曼清院
。里面传来轻歌曼舞的声音，有几个姑娘在门口招呼着来往的行人。许
多外来的武林人士都到那里去寻欢作乐。
long);

  set("exits", ([ 
  
      "south":__DIR__"beijie2",
      "west":__DIR__"manqingyuan",
      "north":__DIR__"beimen",
         ]));
  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
}

