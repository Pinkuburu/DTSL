// /d/gaoli/yizhan
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "驿站");
	set("long", @LONG
这里是山海关唯一的一家驿站，现在因为战乱这里也给百姓送信，
你要是有什么物品的话可以托这里的人转交，当然是要花钱的了。但只
要是交到这里的物品你就放心好了，这里的信誉是首屈一指的。
LONG
	);
set("exits", ([
                "west" : __DIR__"beidajie",       
	]));
       setup();
	replace_program(ROOM);
}	
