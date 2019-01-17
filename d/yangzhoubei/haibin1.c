
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","海滨");
  set ("long", @LONG
这里海滨了。东边就是茫茫的大海。可以听到海浪拍击岸边的声音。
面对茫茫大海，令人豪气顿生。
LONG);

  set("exits", ([ 
 "northeast":__DIR__"haibin2",
 "southwest":__DIR__"caodi3",
"northwest":"/d/shanhaiguan/nanchengmen"
        ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
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
   if(strsrch(time,"八月")==-1
    &&strsrch(time,"七月")==-1
     )
    return notify_fail("你现在什么也领会不出来。\n");
   
   msg="$N听着海边的海啸声，看着浪花拍打着暗边的礁石，不由得对伏鹰枪法有了更深的认识！\n";
   message_vision(msg,ob);
   ob->set("perform_quest/fengyu",1);
   return 1;
}