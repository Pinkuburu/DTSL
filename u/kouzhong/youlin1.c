
#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "小树林");
	set("long", @LONG
这是一片小树林。树林虽小，但似乎暗合机关之理，你不由小心起
来。据说进去的人很少有能活着出来。还是小心为妙。
LONG
	);


	set("exits", ([
        "east" : "/d/chengdu/wroad2",
		"west":__DIR__"youlin2",
	]));
       set("outdoors", "成都");
	setup();
}

int valid_leave(object ob,string dir)
{
  if(dir=="west"&&ob->query_skill("dodge",1)<120){
  ob->add_temp("mark/youlin1",1);
  if(ob->query_temp("mark/youlin1")<5)
  return notify_fail("只听嗖地一声，一支箭从你的头上射过，你吓了身冷汗，停住了脚步！\n");
  else{
  message_vision("只听嗖地一声，一支箭正中$N的额头！\n",ob);
  ob->delete_temp("mark/youlin1");
  ob->unconcious();
  return 0;
  }}
  return ::valid_leave(ob,dir);
}

