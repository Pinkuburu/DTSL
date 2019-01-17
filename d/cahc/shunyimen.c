
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","顺义门");
  set ("long", @LONG
这是一座巍峨的皇城大门，高高的门楼上方刻着“ 顺义门 ”三个金
壁辉煌的大字，从这里向东，就进入皇城了，西面是安化大街，几个官
兵腰配兵器守在门口，闲杂人等一律不允许靠近。
LONG);

  set("exits", ([ 
 "east":__DIR__"dafusi",
 "west":"/d/changan/ahdajie4",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":2,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

