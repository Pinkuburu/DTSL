
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","尹府");
  set ("long", @LONG
这里是一片豪华的府第，雕梁画栋，金壁辉煌，府门前的家丁凶神
恶煞，一看就知道这所府第的主人不是什么好人，听说他是现在皇上宠
爱的妃子的父亲，而且他本人武功高强，是什么邪派的传人呢？难怪会
如此嚣张。
LONG);

  set("exits", ([ 
 "east":__DIR__"asdajie3",
         ]));
set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}
