// /d/gaoli/shufang.c
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "书房");
	set("long", @LONG
这是塞漠帮帮主的书房，屋里干净敞亮，书架上放满了武学典籍，
书案上都是塞漠帮来往的书信。
LONG
	);
set("exits", ([
                "west" : __DIR__"baihutang",       
	]));
       setup();
	replace_program(ROOM);
}	
