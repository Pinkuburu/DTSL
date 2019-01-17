
inherit ROOM;

int do_move();
void create ()
{
  set ("short","厢房");
  set ("long", @LONG
这里是一间小厢房，只见这里黑蒙蒙的，几乎看不到什么出口。旁
边的墙上挂着一个牌子，上面写着“兑”。四下望去，旁边好象还有几
个屋子。墙上还有一个机关把手，似乎可以推[move]一下。
LONG);

  set("exits", ([ 
  "north":__DIR__"wu"+(1+random(8)),
  "west":__DIR__"wu"+5,
  "east":__DIR__"wu"+(1+random(8)),
  "south":__DIR__"wu"+(1+random(8)),
     ]));

  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_move","move");
}

int do_move()
{
  object ob;
  object weapon;
  ob=this_player();
  if(!ob->query_temp("dtsl_lev1_quest_chanzhang/step9"))
  return notify_fail("你使足了力气也推不动把手。\n");
  ob->delete_temp("dtsl_lev1_quest_chanzhang/step9");
  ob->set_temp("dtsl_lev1_quest_chanzhang/step10",1);
  message_vision("$N推了把手一下。\n",ob);
  weapon=new(__DIR__"jinlong-zhang");
  message_vision("$N只听喀哒一声，墙上裂开一个洞，一个禅杖滑落了下来。\n",ob);
  weapon->move(ob);
  return 1;
}