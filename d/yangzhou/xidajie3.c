
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是扬州城的西大街。东面就是扬州的瘦西湖边了。那里是扬州
最热闹的地方。南面是扬州的热闹集市之一西集市。从这里就可以听见
讨价还价的声音。北面是一家客栈，看起来生意不错，店小二正热情地
招呼着来往的行人。
LONG);

  set("exits", ([ 
 "east":__DIR__"xihudi2",
 "west":__DIR__"xidajie2",
 "north":__DIR__"kezhan",
 "south":__DIR__"xijishi",
        ]));
  set("objects",([
	  __DIR__"npc/haoke":1,
	  ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

