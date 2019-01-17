// 
inherit ITEM;
#include <ansi.h>
#include "include/story.h"
#include "include/map.h"

int do_ask(string arg);


void create()
{
	
	
	
	set_name("符文", ({"fuwen"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long","符文");
		set("no_drop",1);
		set("no_give",1);
		set("no_get",1);
		set("no_save",1);
		set("material", "铁");		
	}
	setup();
}

void set_status()
{
   mapping select_story;
	
   select_story=story[random(sizeof(story))];
	
   set("story",select_story);
   set("long",select_story["key_msg"]);
}

void init()
{
  add_action("do_ask","xunwen");
 
}

int do_ask(string arg)
{
   object ob,target,thing;
   string t_name,thing_name;
   string *where;
   int i;
   object paper;
   mapping select_story;
   
   ob=this_player();
   select_story=query("story");
   
   if(!arg||sscanf(arg,"%s with %s",t_name,thing_name)!=2)
   return notify_fail("请使用 xunwen xx with xx。\n");
   
   if(!objectp(target=present(t_name,environment(ob))))
   return notify_fail("这里没有这个人。\n");
   if(!target->is_character())
   return notify_fail("那不是活人啊！\n");
   if(userp(target))
   return notify_fail("对方不会给你任何信息的！\n");
   
   if(!objectp(thing=present(thing_name,ob)))
   return notify_fail("你身上没有这个东西。\n");
   
   if(thing!=this_object())
    return 0;
   
   if(base_name(target)!=select_story["key_npc"])
   return notify_fail("你把手中的"+thing->query("name")+"给"+target->name()+
   "看了看，"+target->name()+"摇摇头，这个东西我也不知道是什么。\n");
   
   paper=new(__DIR__"obj/map");
   
   where=keys(map);
   i=random(sizeof(where));
   paper->set("place",where[i]);
   paper->set("long",select_story["map_msg"]);
   paper->set("target_npc",select_story["target_npc"]);
   paper->set("exp_lev",select_story["exp_lev"]);
   paper->set("hp_lev",select_story["exp_lev"]);
   paper->set("force_lev",select_story["exp_lev"]);
   paper->set("skill_lev",select_story["skill_lev"]);
   paper->set("kill_msg",select_story["kill_msg"]);
   paper->set("reward_exp",select_story["reward_exp"]);
   paper->set("reward_pot",select_story["reward_pot"]);
   if(stringp(select_story["target_name"]))
    paper->set("target_name",select_story["target_name"]);
   
   paper->move(ob);
   tell_object(ob,target->name()+"给了你一张地图。\n");
   message_vision(select_story["tell_msg"]+"据说他藏身在"+map[where[i]]+"，你帮我杀了他吧！\n",
     target,ob);
   
   destruct(thing);
   return 1;
}