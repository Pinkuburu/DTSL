
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","西市署");
  set ("long", @LONG
这是西市署，而令和市丞就在这里办事，管理市中的一切买卖。凡
是以次充好，以假冒真，粗制滥造，短斤少两者，一旦查实，货物没收，
人则杖责。市场用的戥秤均由他们统一制作供应，严禁私制，市场物价
由他们厘定。这都是由秦王府拟出来的利民德政。
LONG);

  set("exits", ([ 
 "east":__DIR__"xishidongjie3",
         ]));

  set("valid_startroom", 1);
  setup();
 
}
