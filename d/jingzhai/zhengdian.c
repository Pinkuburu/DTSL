
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIW"正殿"NOR);
  set ("long", @LONG
这里是慈航静斋的正殿。正面有一尊大佛像，旁边还有几个小佛像，
看起来都是神态安详。正面悬挂着一个牌匾，上面写着「清心普善殿」。
有几个弟子在那里诵经念佛。
LONG);

  set("exits", ([ 

  "north":__DIR__"houqingdian",
  "south":__DIR__"huayuan",
  "east":__DIR__"wuwangdian",
  "west":__DIR__"jingxindian",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
  
  set("valid_startroom", 1);
  setup();
 
}

