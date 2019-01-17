
#include <room.h>

inherit ROOM;
string do_look();
int do_wa();
int do_ke();
int do_tui(string arg);
int do_zuan(string arg);
void create()
{
	set("short", "坟地");
	set("long", @LONG
这是一坟地。这里只有一个孤零零的坟，不知道埋葬的是什么人。
前面还立着一个石碑(bei) 。一阵冷风吹来，你不禁打了个寒战。
LONG
	);


	set("exits", ([
		"east" :__DIR__"xiaojing2",
	]));
	set("item_desc",([
	 "bei":(:do_look:),
	 ]));
       set("outdoors", "成都");
	setup();
}

void init()
{
  add_action("do_ke","ketou");
  add_action("do_wa","wa");
 // add_action("do_tui","tui");
 // add_action("do_zuan","zuan");
}

string do_look()
{
  object ob;
  ob=this_player();
  if(!ob->query_temp("ask_shi"))
  return "上面的字迹不清楚，不知道是谁的墓碑。\n";
  return "霸刀岳山之墓。\n";
}

int do_wa()
{
  object me;
  string msg;
  
  me=this_player();
  
  if(!me->query_temp("ask_shi")||
     !me->query_temp("ketou")
    )
  return notify_fail("你挖了半天，发现什么也挖不到。\n");
  
  msg="\n$N突然挖到一个卷轴，上面记载了岳山刀法的绝学。\n"+
      "$N仔细看着卷轴，从中领悟出了霸刀的精髓！\n"+
      "$N奋力一震双臂，卷轴裂成片片，消失在风中。\n";
  message_vision(msg,me);
  me->do_command("haha");
  me->set("perform_quest/badao",1);
  return 1;
  
}
int do_ke()
{
  object ob;
  ob=this_player();
  ob->set_temp("ketou",1);
  message_vision("$N恭恭敬敬地磕了一个头。\n",ob);
  return 1;
}
/*int do_tui(string arg)
{
  object me;
  me=this_player();
  if(!arg||arg!="石碑"||!me->query_temp("ketou"))
  return notify_fail("什么?\n");
  if(me->query("force")<2000||
  me->query_skill("force",1)<100)
  return notify_fail("你推了半天，发现石碑纹丝不动。\n");
  if(me->query("sen")<20)
  return notify_fail("你累的头昏眼花，石碑纹丝不动。\n");
  message_vision("$N用力一推，只听石碑在轰隆声中歪在一旁！\n",me);
  tell_object(me,"前面漏出一个黑洞，似乎可以钻进去.\n"+
                 "石碑后面写着几个字：入此洞学习武功者，\n"+
                 "一生只有一次进去的机会，好好把握！\n");
  me->set_temp("can_zuan",1);
  return 1;
}

int do_zuan(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="洞"||
  !ob->query_temp("can_zuan"))
  return notify_fail("什么？\n");
  if(ob->query("only/xiulian"))
  return notify_fail("一个人一生只能进去一次!\n");
  if(ob->query("eff_kee")*100/ob->query("max_kee")>25)
  return notify_fail("你钻不进去！\n");
  message_vision("$N拔开杂草，钻了进去！\n",ob);
  CHANNEL_D->do_channel(this_object(), "rumor",
   sprintf("%s决定隐世修炼，要退出江湖一段时间了！", ob->name()));
  ob->add_array("only","xiulian");
  ob->move(__DIR__"mishi");
  return 1;
}
*/