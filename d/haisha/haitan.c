
#include <ansi.h>
inherit ROOM;
int do_yell(string arg);
int do_wa();
void create ()
{
  set ("short","海滩");
  set ("long", @LONG
这里是渔村的尽头了，东边是一望无际的大海，阵阵海浪拍向岸边。
海风吹来，带来一阵咸涩的气息。
LONG);

  set("exits", ([ 
  "west":__DIR__"xiaolu3",
  "northwest":"/d/clone/room/orgsaferoom/haisha/longhutang",
         ]));
  set("outdoors","haisha");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_yell","yell");
   add_action("do_wa","wa");
}

int do_yell(string arg)
{
    object me;
    me=this_player();
    if(!arg||(arg!="boat"&&arg!="船家"))
    return notify_fail("你要喊叫什么？\n");
    message_vision("$N大声朝大海中喊道：船家～～～～　～～～～\n",me);
    tell_object(environment(me),"远处有人喊道：现在谁敢在海沙帮停船啊，你省省吧～～～\n");
    return 1;
    
}
int do_wa()
{
  object ob;
  object cao;
  
  ob=this_player();
  if(ob->is_busy()||
     ob->is_fighting())
  return notify_fail("你正忙着呢！\n");
  if(query("no_dig"))
  return notify_fail("这里好象没有什么东西了。\n");
  if(ob->query("sen")<50)
  return notify_fail("你感到精神疲惫，好象该休息一下了。\n");
  message_vision("$N在地上挖了起来。\n",ob);
  ob->receive_damage("sen");
  if(random(20)>10){
  	cao=new("/d/quest/poison/obj/cao1");
  	cao->move(environment(ob));
  	message_vision("$N挖到了一棵"+cao->query("name")+"。\n",ob);
  	set("no_dig",1);
  	return 1;}
  ob->start_busy(2);
  return 1;
}