
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","大沙漠");
       set("long", @LONG
这是一片一望无际的大沙漠。你一进来就迷失了方向。看来要走出
这块沙漠并非易事。
LONG);
        set("outdoors", "shamo");
        set("exits", ([
                "east" : __DIR__"shamo"+(1+random(4)),
                "west" : __DIR__"shamo"+(1+random(4)),
                "south" : __DIR__"shamo"+(1+random(4)),
                "north" :"/d/suiye/dadao2",
        ]));             
        setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "west") me->add_temp("mark/steps",1);
        if ( dir == "east") me->add_temp("mark/steps",-1);

//     if (me->query_temp("mark/steps") == 5){
     if (me->query_temp("mark/steps") >= 5){
         me->move("/d/suiye/dadao2");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"从南边的大沙漠走了过来。\n", ({ me }));
         return notify_fail("你累得半死，终於走出了沙漠。\n");
         }  
//     if (me->query_temp("mark/steps") == -5){  
     if (me->query_temp("mark/steps") <= -5){  
         me->move("/d/tuyuhun/silk9");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"从西边的大沙漠走了过来。\n", ({ me }));
         return notify_fail("你累得半死，终於走出了沙漠。\n");
         }
        return ::valid_leave(me,dir);
}
