
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIC"新中桥"NOR);
  set ("long", @long
这是中土第一座开合桥，出自天下巧艺大宗师鲁妙子的设计。当楼
船等大型船只经过时，桥面可从中分开，让其通过，令人惊叹不已。
long);

  set("exits", ([ 
  

  "northdown":__DIR__"kaiheqiao1",
  "southdown":__DIR__"kaiheqiao3",
         ]));

  set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

