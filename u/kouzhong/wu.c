
#include <room.h>
#include <ansi.h>
inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "幽林小筑");
	set("long", @LONG
这是一座小茅屋。里面收拾的整整齐齐。后面是一座小花园，四周
是一排竹栅栏。茅屋的摆设不是很多，除了几个竹椅子和一床就没有什
么了。茅屋上面有一个小牌子，上面用隽秀的字体写着“幽林小筑”四
个字。
LONG);


	set("exits", ([
		"north" :__DIR__"youlin2",
		"south":__DIR__"youlin3",
		"west":"/d/quest/bawangdao/xiaojing",
		"east":__DIR__"youlin1",
	]));
	set("objects",([
       "/d/chengdu/npc/shiqingxuan":1,
	   ]));
       
      setup();
}

