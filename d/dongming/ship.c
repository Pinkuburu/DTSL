
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","巨舟");
  set ("long", @LONG
这里是个艘巨舟，用来行驶于大海之中。只见浪花不住地拍打着船
身，几名水手的号子声远远传了出去。
LONG);

 set("outdoors","ship");
  set("valid_startroom", 1);
  setup();
 
}

