
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","南大街");
  set ("long", @LONG
这里是扬州城的南大街。南面就是扬州的南城门了。东面有一家钱
庄。北面是扬州的五大集市之一南集市。这里热闹非凡，人来人往。不
时有武林人士从你的身旁走过，不时用奇怪的眼神打量着你，似乎想从
你身上看出和氏璧的痕迹。
LONG);

  set("exits", ([ 
 "east":__DIR__"qianzhuang",
 "northwest":__DIR__"nanjishi",
 "southeast":__DIR__"nanmen",
        ]));
  set("objects",([
     "/d/clone/npc/simadekan":1,
     ]));
  set("outdoors","yangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

