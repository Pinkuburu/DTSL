
#include <ansi.h>
inherit ROOM;

int do_climb(string arg);

void create ()
{
  set ("short","松树");
  set ("long", @LONG
这是一个生长在悬崖边的松树。下边是万丈深渊，白云飘忽在你的
身边。抬头望去，上面是陡峭的悬崖，看不到尽头。一阵风吹来，松树
晃了几晃，震下了片片积雪。仔细看去，旁边似乎还有一个小山洞。
LONG);

  set("exits", ([ 
 "enter":__DIR__"mishi1",
        ]));
  set("outdoors","wolongling");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_climb","climb");
}

int do_climb(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="up")
  return notify_fail("你要朝那里爬？？\n");
  message_vision("$N手攀悬崖，朝上爬去。\n",ob);
  ob->move(__DIR__"wolong4");
  return 1;
}
