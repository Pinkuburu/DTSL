
inherit ROOM;
void create()	
{
	set("short","扬州玩家村村口");
	set("long", @LONG
这里是扬州玩家村的村口。玩家村是大唐中结为夫妇的武林
侠士居住的地方。目前这里还没有什么人口。南边就是扬州的长
江北岸了，从这里可以看到长江翻滚的江水。北边是进入村子的
道路。只听里边有嬉笑吵闹的声音，似乎非常热闹。
LONG);
    set("exits", ([
	        "southeast" :"/d/hangzhou/jiangbei",
	        "north":__DIR__"nandajie1",
 	]));
 	
      setup();
      replace_program(ROOM);
	
}
