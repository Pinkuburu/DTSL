inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY"战舰"NOR);
	set("long", @LONG
这是一艘巨大的战舰。上面有很多官兵在到处走动。战舰的桅杆上
飘着一面巨大的旗子，上面写着“宇文”两个大字，随风飘扬，好不威
风。
LONG);
	set("outdoors","长生诀");
        set("objects",([
           __DIR__"npc/yuwen-huaji":1,
           ]));
        set("exits",([
          "out":"/d/job/sjbjob/dongan",
          ]));
	setup();      
}
