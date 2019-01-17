
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","海滨");
  set ("long", @LONG
这里是海滨。一阵风吹过，满是咸涩的气息。据说经常有人在这里
贩卖私盐，所以有很多官兵在这里巡视。
LONG);

  set("exits", ([ 
 "east":__DIR__"haibin3",
 "southwest":__DIR__"haibin1",
        ]));
  set("objects",([
     __DIR__"npc/guanbing":2,
     ]));
  set("outdoors","yangzhoubei");
  
  set("valid_startroom", 1);
  setup();
 
}

int valid_leave(object me,string dir)
{
   object ob;
   if(me->query("gender")=="女性"&&me->query_per()>26
     &&present("guan bing",environment(me))
     &&me->query("family/family_name")!="慈航静斋")
     tell_object(me,"官兵狞笑道:"+RANK_D->query_respect(me)+"长得不错嘛！\n");
   if(objectp(ob=present("guan bing",environment(me)))&&
      me->query("gender")=="男性"&&random(10)>5)
    { 
      switch(MONEY_D->player_pay(me,30) ){
      	case 0:
      	case 2: return notify_fail("官兵哼道：没钱？没钱就别过去了！\n");
          }
       message_vision("官兵搜走了$N身上三十文铜钱！\n",me);
       
     }
    return ::valid_leave(me,dir);
}