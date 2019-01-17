// /d/taiyuan/road2.c
// Room in 太原
// modify by yang

#include <room.h>
inherit ROOM;
void create()	
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商
的、赶着大车的马夫，熙熙攘攘，非常热闹。不时还有两三骑快马从身
边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的杨树林。
LONG
        );
set("outdoors", "/d/taiyuan");
set("exits", ([
                "east":__DIR__"road1", 
                "southwest":__DIR__"road3", 
                
	]));
       setup();
       replace_program(ROOM);
}


