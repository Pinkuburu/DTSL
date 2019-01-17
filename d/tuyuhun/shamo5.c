
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
                "south" : __DIR__"shamo2",
                "north" : __DIR__"shamo"+(1+random(4)),
        ]));             
        setup();
}


void init()
{
  add_action("do_linghui","linghui");

}

int do_linghui()
{
   object ob;
   string time,msg;
   
   ob=this_player();
   
   if(ob->query_skill("fuying-spear",1)<160)
   return 0;
   if(ob->query("perform_quest/fengsha"))
   return 0;
   if(ob->query("perform_quest/fengyu"))
   return 0;
   
   time=NATURE_D->game_time();
   if(strsrch(time,"三月")==-1
    &&strsrch(time,"四月")==-1
     )
    return notify_fail("你现在什么也领会不出来。\n");
   
   msg="$N看着沙漠中风沙，不由得对伏鹰枪法有了更深的认识！\n";
   message_vision(msg,ob);
   ob->set("perform_quest/fengsha",1);
   return 1;
}