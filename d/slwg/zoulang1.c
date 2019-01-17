
#include <room.h>

inherit ROOM;
void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是石龙武馆的走廊。南边是武馆的大门。再往北走，就是武馆
的正厅了。有很多弟子在这里走来走去，看起来非常热闹。东边不时传
来呼喝练武的声音。
LONG
);


	set("exits", ([
		"north" :__DIR__"zoulang2",
                "south":__DIR__"damen",
                "east":__DIR__"zhangfang",
                "west":__DIR__"bingqipu",                
                "阴癸派":"/d/yinkui/door",
                "净念禅院":"/d/chanyuan/miaodoor",
                "花间":"/d/luoyang/zhonggulou",
                "慈航静斋":"/d/jingzhai/door",
                "突厥":"/d/changan/xpdajie6",
                "东溟派":"/d/dongming/gangkou2",
                "弈剑派":"/d/gaoli/xingguan",
                "宋家堡":"/d/lingnan/door",
	]));
	/*set("objects",([
	    __DIR__"npc/shoumen_dizi":1,
	    ]));*/
       set("no_fight",1);
       set("outdoors", "slwg");
	setup();
}

int valid_leave(object ob,string dir)
{
  
   if(ob->query("combat_exp")<20000&&dir=="south")
     return notify_fail("你经验这么低，出武馆太危险了！\n");
    
   return ::valid_leave(ob,dir);
}