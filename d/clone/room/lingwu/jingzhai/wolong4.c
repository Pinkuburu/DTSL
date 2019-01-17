
#include <ansi.h>
inherit ROOM;

int do_jump(string arg);

void create ()
{
  set ("short","飞云崖");
  set ("long", @LONG
这里就是卧龙岭上的飞云崖，东边是深不见底的深渊，白云隐隐浮
现在其上。峭壁险峻，如同用刀切开一般光滑。西边是浮云坪。极目望
去，群上巍峨的景观尽收眼底。
LONG);

  set("exits", ([ 
 "west":__DIR__"wolong3",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_jump","jump");
}

int do_jump(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="down")
  return notify_fail("你要往哪里跳？？\n");
  if(ob->query("pker"))
  return notify_fail("通缉犯还是老实点吧！\n");
  message_vision("$N双脚一点地，纵身朝飞云崖下纵去！！\n",ob);
  ob->move(__DIR__"songshu");
  return 1;
}
