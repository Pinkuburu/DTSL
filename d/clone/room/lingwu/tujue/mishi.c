
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short",HIB"密室"NOR);
  set ("long", @LONG
这里是一间密室，四周黑洞洞的，看不到任何出口。这里有
三个木马，似乎是红色、白色和蓝色。
LONG);
 set("objects",([
   __DIR__"horse1":1,
   __DIR__"horse2":1,
   __DIR__"horse3":1,
   ]));
 set("valid_startroom", 1);
  setup();
 
}
