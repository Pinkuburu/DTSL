
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","景风门");
  set ("long", @LONG
这是一座巍峨的皇城大门，高高的门楼上方刻着“ 景风门 ”三个金
壁辉煌的大字，从这里向西，就进入皇城了，东面是安上大街，几个官
兵腰配兵器守在门口，闲杂人等一律不允许靠近。
LONG);

  set("exits", ([ 
 "west":__DIR__"shaofujian",
 "east":"/d/changan/asdajie4",
        ]));
  set("objects",([
	  "/d/changan/npc/bing":2,
	  ]));

  set("outdoors","changan");
  
  set("valid_startroom", 1);
  setup();
 
}

