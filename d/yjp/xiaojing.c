// /d/gaoli/ suishixiaolu2
// Room in  碎石小路
// laowuwu 99/06/27
inherit ROOM;
void create()	
{
	set("short", "碎石小路");
	set("long", @LONG
你顺着小路向前走，发现不远的地方有一处精舍，那里就是
弈剑大师＂傅采林＂的弈剑小筑。
LONG
	);
set("outdoors", "/d/yijiange");
set("exits", ([
                "southwest" : "/d/gaoli/xiaoxi1",
                "northwest" : __DIR__"zhuangmen",  
                "northeast": __DIR__"zhulin",            
           	]));
       setup();
	replace_program(ROOM);
}	
