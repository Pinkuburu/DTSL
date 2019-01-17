
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是一条山路。东面有一座凉亭。北面有一个水潭。南边是峨眉
山的论剑台，那里是武林中人比武的地方，不时传来了呼喝打斗的声音。
西面就是著名的碧峰峡了。
LONG);

  set("exits", ([ 
 "east":__DIR__"liangting",
 "west":__DIR__"bifengxia",
 "north":__DIR__"shuitan",
 "southup":__DIR__"lunjiantai",
 "northup":__DIR__"jietuopo",
      ]));
  set("outdoors","emeishan");
 set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object ob,string dir)
{
   if(dir=="southup"&&ob->query("pker"))
    return notify_fail("通缉犯上不去擂台！\n");
   return ::valid_leave(ob,dir);
}

