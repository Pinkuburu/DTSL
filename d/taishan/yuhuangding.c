
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","玉皇顶");
  set ("long",@LONG
这里是泰山的玉皇顶。此处便是泰山绝顶。这里有一座玉帝观，观
前为古登封台，厉代皇帝封禅的仪式都是在这里举行。台下有一无字碑，
据说是汉武所立.不远处有一石碣，上书「孔子小天下处」。
LONG);

  set("exits", ([ 

 "westdown":__DIR__"bixiaci",
// "west":"/d/clone/biwutai/meeting_room",
          ]));

set("outdoors","taishan");
  
  set("valid_startroom", 1);
  setup();
 
}

