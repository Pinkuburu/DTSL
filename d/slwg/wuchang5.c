
#include <room.h>

inherit ROOM;

int do_action(string arg);

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是石龙武馆的练武场，是石龙武馆初级弟子学习武功的地方。
你可以在这里打沙袋来提高自己的武功。只见这里尘土飞扬，数名弟子
正在那里练得热闹。
LONG
);


	set("exits", ([
		"south" :__DIR__"wuchang2",
		
	]));
	/*set("objects",([
	     __DIR__"npc/dizi":1,
	    ]));*/
       set("no_fight",1);
       set("lianwu","打沙袋");
       set("over_work","你的打沙袋已经练习得可以了，可以去找教头了[task ok]。\n");
       set("work_msg",({
       "你对着沙袋啪啪打去，觉得武学的修为有了进一步的提高！\n",
       "你双拳连续出击，打得沙袋劈啪做响，尘土飞扬。\n",
       "你一阵快拳打去，只见沙袋乱晃，几乎碎裂开来！\n",
       }));
       set("outdoors", "slwg");
	setup();
}

void init()
{
  add_action("do_action","lianwu");
}

#include "work_skill.c"