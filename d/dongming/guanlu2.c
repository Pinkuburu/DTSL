
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "官路");
	set("long", @LONG
这里是一条官路。北边就是九江的南门了。这里的行人很多。经常
有人骑着马从你的身旁驰过。一条笔直的石板大道通向前方，路上不时
的有南来北往的车马经过，不少行人手持各种兵器，看来都是习武之人。
LONG);
	set("exits", ([
		"southeast":__DIR__"guanlu1",
		"north":"/d/jiujiang/nanmen",
		]));
      set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
       
       
}

