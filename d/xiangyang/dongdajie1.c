
inherit ROOM;


void create ()
{
  set ("short","东大街");
  set ("long", @LONG
这里是襄阳的东大街。由于是战乱年代，所以很少有人在街上闲逛，
显得冷冷清清。只有几个捕头经常从这里走过，冷冷地打量着路边的小贩。
北边是一个小巷，是襄阳地痞流氓的聚点。
LONG);

  set("exits", ([ 
 "east":__DIR__"dongdajie2",
 "west":__DIR__"guangchang",
 "north":__DIR__"xiaoxiang1",
        ]));
        set("objects",([
        __DIR__"npc/qianduguan":1,
        ]));
  set("outdoors","xiangyang");
  
  set("valid_startroom", 1);
  setup();
 
}

