
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name("火折", ({ "huo zhe", "huo","zhe","fire" }) );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "有了这个火折，你就可以在黑天看到路了。\n");
    set("value",500);
    set("unit", "个");
  }
  setup();
}
