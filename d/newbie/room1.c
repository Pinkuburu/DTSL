
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","新人篇");
  set ("long", @LONG
这里将会教你学会在大唐中生活的基本技能。你可以使用 help 命
令来得到帮助。
不过如果你没有接触过泥巴生活，还是使用 help newplayer 看看吧！
如果你想得到更直观的帮助，请访问以下两个站点：
www.dtsky.com 
dt66.126.com 
上面有很详细的帮助说明。
如果想向在线的江湖豪客救助，可以使用各种频道。目前频道有：
chat    闲聊频道。如：【闲聊】真冰河(Yanyan)：大家好
party   门派频道，必须加入门派才可以使用。
rumor   谣言频道。谁都可以用，造谣的好东西啊！
banghui 帮会频道，必须加入帮会才可以用。
dt      大唐频道。

可以使用 tune 命令来看看目前可以使用哪些频道，而 tune 频道名字
则可以关掉这些频道。
LONG);

  set("exits", ([ 
 "east":__DIR__"room2",
 "west":__DIR__"room3",
 "north":__DIR__"room4",
 "south":__DIR__"door",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

