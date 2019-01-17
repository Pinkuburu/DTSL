
#include <ansi.h>
inherit ROOM;
#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huanghe_dukou2"
#define TO __DIR__"huanghe_dukou1"
#include "/std/shiproom.c";
void create ()
{
  set ("short","黄河渡口");
  set ("long", @LONG
这里是黄河的渡口。面前黄河滚滚，气势惊人。只有一叶扁舟载来
往的行人。有很多行人在这里乘船，非常热闹。许多小商小贩在这里叫
卖，向即将登船展示自己的货物。货船的监工正在打骂着搬货的工人，
催促的声音不绝。
LONG);

  set("exits", ([ 

  "northeast":"/d/liyang/dadao9",
"northwest":"/d/taiyuan/sroad8",
         ]));
set("outdoors","luoyang");
  set("valid_startroom", 1);
  setup();
 
}

