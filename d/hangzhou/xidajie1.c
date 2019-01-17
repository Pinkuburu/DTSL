
inherit ROOM;


void create ()
{
  set ("short","西大街");
  set ("long", @LONG
这里是杭州的西大街。往西走可以到杭州最吸引人的地方西湖。东
边是杭州的中心了。有很多游客都在往西湖走去。北边有一家酒楼，传
来了阵阵酒香，喝酒吵闹的声音同时也充斥了整个街头。
LONG);

  set("exits", ([ 
 "north":__DIR__"xihulou",
  "west":__DIR__"xidajie2",
  "east":__DIR__"center",
         ]));
  set("objects",([
	  __DIR__"npc/wushi":1,
	  ]));

set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

