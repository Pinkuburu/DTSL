
#include <ansi.h>
inherit ROOM;
string do_joke();
void create ()
{
  set ("short",HIC"巫师工作室"NOR);
  set ("long", @LONG
这里是巫师工作的地方。面前的放着一张大桌子，上面放着一个大
笔记本，记录了巫师的工作进程。旁边的墙上还挂着几件衣服。窗外是
扬州美丽的景色，车水马龙，好不热闹。墙角上还放着一个沙发，上面
蜷缩着一个人(ren)，正在那里睡觉 ，不知道是谁。
LONG);

  set("exits", ([ 
// "south":__DIR__"wizroom2",
         ]));
    
    set("item_desc",([
      "ren":(:do_joke:),
      ]));
    
    setup();
  "/obj/board/task_b.c"->foo();
  
}

string do_joke()
{
  object ob;
  ob=this_player();
  return HIC+ob->name()+HIC+"正流着口水躺在那里，看起来很疲劳了。\n"NOR;
}
