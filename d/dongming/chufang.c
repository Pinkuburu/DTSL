
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"厨房"NOR);
	set("long", @LONG
这里是东溟派的厨房。有几名厨师正在那里忙着做饭，饭菜的香气
阵阵飘入你的鼻中，你不禁有些饿了。旁边的桌子上放着一些米饭和一
些水。有几名东溟弟子正在那里狼吞虎咽地吃着。
LONG);
	set("exits", ([
	     
		"north":__DIR__"tingyuan",
		
	]));
	set("objects",([
		__DIR__"obj/mifan":3,
		"/d/clone/npc/chuzi":1,
		]));
	set("resource/water",1);
       
       set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

