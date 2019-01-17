
inherit ROOM;

int do_jump(string arg);
void create ()
{
  set ("short","海滩");
  set ("long", @LONG
这里是一片海滩，徐徐海风吹来，带来了阵阵的凉意。海水不住地
拍打着岸边的礁石，发出一阵阵的轰鸣的声音。据说东溟有个武功的秘
密就藏在此处，不知是真是假。
LONG);

  set("exits", ([ 

  "south":"/d/dongming/haitan2",
      ]));

  set("valid_startroom", 1);
  set("outdoors","dongming");
  setup();
 
}

void init()
{
 add_action("do_jump","jump");
}

int do_jump(string arg)
{
   object ob;
   
   ob=this_player();
   if(!arg||arg!="大海")
   return notify_fail("你要往哪里跳？\n");
   if(ob->query_skill("leiting-chuifa",1)<160
    ||ob->query("perform_quest/duomeng")
    ||ob->query("perform_quest/yanyu")
    ||ob->query("perform_quest/pili")
     ){
    ob->start_busy(3);
    return notify_fail("你碰地一下撞在了旁边的岩石上，眼冒金星！\n");
   }
   message_vision("$N深吸了一口气，朝海水中扎去！\n",ob);
   ob->move(__DIR__"haidi1");
   return 1;
}
