
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "官路");
	set("long", @LONG
这里是一条官路。北边不远就是九江城了。经常有人骑着马从你的
身旁驰过。一条笔直的石板大道通向前方，路上不时的有南来北往的车
马经过，不少行人手持各种兵器，看来都是习武之人。
LONG);
	set("exits", ([
		"southeast":__DIR__"dalu7",
		"northwest":__DIR__"guanlu2",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

