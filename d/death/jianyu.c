
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIB"监狱"NOR);
	set("long", @LONG
这里是一座监狱，是众神审判通缉犯的地方。这里四周光线很暗，
四面是高高的围墙，任凭你武功有多高超都无法逃出去。这里站着几个
囚犯，正在忏悔着自己的罪过。
LONG);
	
	set("no_fight", 1);
	set("no_exercise",1);
	set("no_respirate",1);

	set("valid_startroom", 1);
	setup();
}

