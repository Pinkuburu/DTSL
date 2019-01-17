
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","后殿");
  set ("long", @LONG
这里是后殿。南边阴癸派的议事正殿。这里气氛寂静，四周没有什
么摆设，只有一排烛火照亮这里。墙上画着一些飞仙的壁画，虽然画工
精美，但是遮掩不住诡异的气氛。
LONG);
  set("exits",([
	  "south":__DIR__"zhengdian",
	  "northeast":__DIR__"zhulin",
	  "northwest":__DIR__"caodi",
	  ]));
//set("objects",(["/d/job/ygsongxin/wencai-ting":1,])); move to 九江。

  set("valid_startroom", 1);
  setup();
 
}

