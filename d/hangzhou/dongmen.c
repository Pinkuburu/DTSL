
inherit ROOM;


void create ()
{
  set ("short","东门");
  set ("long", @LONG
这里是杭州的东门。杭州是旅游胜地，所以现在虽然是战乱时局，
但依然掩盖不了这里繁华的景象，同扬州相比，真是有过而无不及。所
以这里的行人很多。这里有两个官兵，在检查着来往的行人。
LONG);

  set("exits", ([ 

  "west":__DIR__"dongdajie2",
  "east":__DIR__"guandao1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","hangzhou");
  
  set("valid_startroom", 1);
  setup();
 
}

