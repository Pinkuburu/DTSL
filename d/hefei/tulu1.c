
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","土路");
  set ("long", @LONG
这里是条土路。这里的行人很少，不时有人骑着马从你的身旁驰过。
偶尔听到一阵阵的野兽叫声，头顶有一些不知名的小鸟在跳来跳去，四周
丛林密布，鲜花绿草若隐若现，随着山谷里吹来的阵阵清风，传来哗哗的
松涛声和一些淡淡的花香。
LONG);

  set("exits", ([ 

  "east":__DIR__"wguanlu2",
  "west":__DIR__"tulu2",
  "south":__DIR__"xiaoqiao",
       ]));
 
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}

