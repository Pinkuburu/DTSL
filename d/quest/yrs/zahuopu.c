inherit ROOM;
#include <ansi.h>
string joke();
int do_search(string arg);
void create()
{
	set("short","杂货铺");
	set("long", @LONG
这是九江的一家杂货铺。如今世道混乱，所以的这里的生意不是很
好做。来来往往也没有几个客人。老板几乎要趴在柜台上睡着了。柜台
的旁边贴着一张白纸[paper].
LONG);
        set("exits",([
 "west":"/d/jiujiang/beidajie1",
          ]));     
        set("item_desc",([
          "paper":(:joke:),
          ]));
        set("objects",([
          __DIR__"boss":1,
          ]));
	setup();      
}
string joke()
{
  object ob;
  ob=this_player();
  return HIW+ob->name()+"欠本店二百两黄金，数年不还，确实无耻的可以。\n\n"NOR+
                        "                                    杂货铺掌柜\n";
}
void init()
{
  add_action("do_search","sou");
}
int do_search(string arg)
{
  object ob;
  object killer;
  ob=this_player();
  if(!ob->query_temp("yrs_find/mianfen"))
  return 0;
  if(time()-query_temp("no_mianfen")<15*60)
  return notify_fail("你搜了半天，发现什么也搜不到！\n");
  set_temp("no_mianfen",time());
  killer=new(__DIR__"guard");
  killer->move(environment(ob));
  tell_object(ob,"你突然发现一包面粉，连忙揣进怀中！\n");
  message_vision(HIR"$N连忙朝$n奔了过来：你这种小偷最可恨了，送死吧！\n"NOR,killer,ob);
  tell_object(ob,"护卫抢走了你手中的面粉！！\n");
  killer->kill_ob(ob);
  return 1;
}
