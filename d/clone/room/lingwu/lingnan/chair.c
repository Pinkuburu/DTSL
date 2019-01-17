
#include <ansi.h>
inherit ITEM;
int do_sit(string arg);
int do_check(string arg);
void create ()
{
  set_name(HIW"虎皮座椅"NOR,({"chair"}));
  set ("long","这是一张红木座椅，上面铺着一张白色的虎皮，\n"+
              "只有堡主才能坐在上面。\n");
  setup();
 
}
int is_get_of(object ob,object ob2)
{
  return notify_fail("这样东西捡不起来。\n");
}
void init()
{
  add_action("do_sit","sit");
  add_action("do_check","check");
}
int do_sit(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||
  (arg!="down"))
  return notify_fail("你要往哪里坐？\n");
  if(ob->query("family_lingwu")!="songjia")
  return notify_fail("你的武功这么弱，怎么能座堡主坐的椅子呢？\n");
  message_vision("$N战战兢兢地坐了下来，可是左晃又晃，觉得很不舒服,觉得应该检查[check]一下。\n",ob);
  return 1;
}
int do_check(string arg)
{
  object ob;
  ob=this_player();
  if(!arg||arg!="座椅")
  return notify_fail("你要检查什么？\n");
  if(ob->query("family_lingwu")!="songjia")
  return notify_fail("什么？\n");
  tell_object(ob,"你开始检查座椅，发现椅子的右把手上雕着一个奇怪的虎头。\n"+
                 "虎头可以向三个方向[up,right,left]扭动[roat].\n");
  return 1;
}
  
  