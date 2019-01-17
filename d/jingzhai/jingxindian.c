
#include <ansi.h>
inherit ROOM;

int do_xiulian();
void create ()
{
  set ("short",HIW"静心殿"NOR);
  set ("long", @LONG
这里是慈航静斋的静心殿。慈航静斋的弟子不时来这里诵经
念佛，以排除心中的杂念。旁边正有一个弟子在那里诵经，清雅
庄重的气氛，不禁让来到这里的人心静如水。
LONG);

  set("exits", ([ 

  "east":__DIR__"zhengdian",
  "west":__DIR__"zoulang1",
       ]));
  set("objects",([
//          __DIR__"npc/qin":1,
	  ]));

  
  set("valid_startroom", 1);
  setup();
 
}

/*
void init()
{
    add_action("do_xiulian","xiulian");
}

int do_xiulian()
{
  object me;string str;
  me=this_player();
  if(me->query("family/family_name")!="慈航静斋")
  return notify_fail("只有慈航静斋的人可以在这里修炼！\n");
  if(me->is_fighting())
  return notify_fail("战斗中如何修炼？\n");
  if(me->is_busy())
  return notify_fail("你还是慢慢来吧！\n");
  message_vision("$N坐了下来，开始修炼[静心拳]。\n",me);
  str="$N在静坐修炼。";
  str=replace_string(str,"$N",me->name());
  me->set_temp("apply/short",({str}));
  me->start_busy((:call_other,this_object(),"doing_xiulian",me:),
                 (:call_other,this_object(),"halt_xiulian",me:));
  return 1;
}

int doing_xiulian(object me)
{
   if(me->query("gin")<10||
      me->query("sen")<10)
    {
      message_vision("$N长嘘了一口气，精神有些疲惫地站了起来。\n",me);
      me->delete_temp("apply/short");
      return 0;
    }
   if(me->query("potential")<40-me->query_int()/2)
    {
      message_vision("$N的潜能不够了，再修炼也不会有见效了。\n",me);
      me->delete_temp("apply/short");
      return 0;
    }
   me->add("sen",-10);
   me->add("gin",-10);
   me->add("potential",-40+me->query_int()/2);
   me->improve_skill("jingxin-quan",me->query_int()/2+(40-me->query_int()/2)*25
                     +me->query_skill("jingxin-quan",1)/5);
   return 1;
}

int halt_xiulian(object me)
{
   message_vision("$N长嘘了口气，站了起来。\n",me);
   return 1;
}

*/