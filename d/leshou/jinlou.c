// /d/zhuojun/jinlou.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "金楼");
	set("long", @LONG
这是一家乐寿城内首屈一指的首饰精品买卖行，这里打造的金银首
饰堪称一绝，做工精细，据说很久以前这里打制的首饰还是供品呢。
LONG
	);
set("exits", ([
                "north"  :__DIR__"dongdajie2",
	]));
set("objects",([
 __DIR__"npc/zhubao-boss":1,
 ]));
       setup();
	replace_program(ROOM);
}	
