
inherit ITEM;
#include <ansi.h>

void create()
{
   set_name(HIC"蓝心蝶"NOR,({ "flower"}) );  	
   set("long", "这是武林中已经绝迹的绝世珍品。\n");
   set_weight(10);       
   set("unit","盆");
   set("value",100000000);
   setup();
 
}

int is_get_of(object pal,object ob)
{
  return notify_fail("这个东西不能拿起来。\n");
}
