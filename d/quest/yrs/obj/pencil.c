
inherit ITEM;
#include <ansi.h>
int do_draw(string arg);
void create()
{
        set_name(YEL"画笔"NOR, ({"pencil"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
    else  {
           set("unit", "个");
           set("yrs","pencil");
           set("long", "这是一个小画笔．\n");
        }
}

void init()
{
  add_action("do_draw","draw");
}

int do_draw(string arg)
{
  object ob;
  object target,source;
  string tname,sname;
  
  ob=this_player();
  if(!ob->query("dtsl_quest_yrs_ok"))
  return notify_fail("你把"+query("name")+"翻来覆去地看，看不出什么端倪.\n");
  
  if(!arg||sscanf(arg,"%s by %s",tname,sname)!=2)
  return notify_fail("请使用 draw 人皮 by 目标\n");
  if(!objectp(target=present(tname,ob)))
  return notify_fail("你身上没有这个东西！\n");
  if(target->query("yrs")!="skin")
  return notify_fail("这上面不能画任何东西！\n");
  if(!target->query("step1"))
   return notify_fail("这上面不能画任何东西！\n");
  if(!objectp(source=present(sname,environment(ob))))
  return notify_fail("你周围没有这个东西！\n");
  if(!source->is_character())
  return notify_fail("那不是活人！！\n");
  if(target->query("weared"))
  return notify_fail("你正戴着人皮面具。\n");
  if(ob->query_skill("yirong-shu",1)<50)
  return notify_fail("你的易容术太低了，无法画好面具。\n");
  message_vision("$N看了$n几眼.\n",ob,source);
  target->set("mask/name",source->query("name"));
  target->set("mask/id",source->query("id"));
  target->set("mask/short",source->short());
  target->set("mask/long",source->long());
  target->set("mask/continue",(ob->query_skill("yirong-shu",1)+30)/10);
  tell_object(ob,"人皮面具画好了，你可以戴了！\n");
  return 1;
}