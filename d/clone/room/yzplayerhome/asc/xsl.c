
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","兰菀相思楼");
  set ("long", @LONG
这里就是天下闻名的兰菀相思楼了，这里的主人是江湖上小
名鼎鼎的 *我意王* 兰斯洛和 *兰心仙子* 菀苑。只见正前方摆
着一张红色的八角方桌，左右有两排太师椅。正上方的墙壁上挂
着唐伯虎的“兰苑相思图”。图的上方是天下英雄赠送的“神仙
侠侣”的牌匾。屋中左右各站着一名俏丽的丫鬟，接待八方的朋
友。北面是相思花园，东面是我意楼。
LONG);

  set("exits", ([ 
 "east":__DIR__"wyl",
 "north":__DIR__"xshy",
 "south":"/d/clone/room/yzplayerhome/huayuan",
      ]));
 set("valid_startroom", 1);
  setup();
 
}

