
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short",HIG"碎石路"NOR);
  set ("long", @LONG
你走在一条碎石路上。只听远处传来诵经的声音，声音平缓，稳而
不乱，令你的心境舒服异常。旁边放着一个香炉，缓缓升起的白烟，把
这里衬托的好象人间仙境一般。
LONG);

  set("exits", ([ 

  "north":__DIR__"huayuan",
  "out":__DIR__"door",
       ]));
  /*set("objects",([
	  __DIR__"npc/bing":2,
	  ]));*/
set("outdoors","jingzhai");
  
  set("valid_startroom", 1);
  setup();
 
}
int valid_leave(object ob,string dir)
{
  if(ob->query("family/family_name")=="慈航静斋"&&dir=="out"
   &&ob->query("combat_exp")<100000)
       return notify_fail("你的功夫太低微了，还是在斋院中修行一段时间在出去吧！\n");
  return ::valid_leave(ob,dir);
}    
