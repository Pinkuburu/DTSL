// /d/zhuojun/yanzixiang.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "胭脂巷");
	set("long", @LONG
这里就是乐寿最有名的胭脂巷了，小巷两旁站着不少倚门卖笑的歌
女，向来往的客人不停地暗送秋波，西面就是胭脂巷里最大的一家妓院，
名叫艳福楼。
LONG
	);
set("outdoors", "/d/zhuojun");
set("exits", ([
		"west" :__DIR__"yanfulou",
                "east"  :__DIR__"guangchang",
	]));
	set("objects",([
	__DIR__"npc/zuihan":1,
	]));
       setup();
	replace_program(ROOM);
}	
