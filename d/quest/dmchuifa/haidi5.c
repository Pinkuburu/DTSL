
inherit ROOM;

int do_push(string arg);
void create ()
{
  set ("short","海底");
  set ("long", @LONG
这里是浅海的底部，这里光线明亮，道道光线从头顶直射下来。海
底礁石错综盘列，但乱中有序，似乎是隐藏着什么阵法。游鱼小虾在你
的身旁游来游去，别有一翻情趣。这里有几个礁石，似乎可以推开它。
LONG);

  set("exits", ([ 

  "east":__DIR__"haidi2",
  "west":__DIR__"haidi3",
  "north":__DIR__"haidi4",
  "south":__DIR__"haidi5",
      ]));

  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_push","push");
}

int do_push(string arg)
{
    object ob,book,fish;
    
    ob=this_player();
    if(!arg||arg!="礁石")
    return notify_fail("你要推什么？\n");
    
    if(ob->is_busy())
    return notify_fail("你正忙着呢！\n");
    ob->start_busy(3);
    
    
    if(ob->query("family/family_name")!="东溟派"
      ||ob->query("perform_quest/pili")
      ||ob->query("perform_quest/duomeng")
      ||ob->query("perform_quest/yanyu")
      )
    return notify_fail("你推了半天，发现礁石纹丝不动。\n");
    if(ob->query_str()<35)
    return notify_fail("你觉得自己的力气太小，推不动礁石。\n");
    
    message_vision("$N费劲力气，只听“轰隆”一声，礁石朝旁边移开。\n",ob);
    tell_object(ob,"你发现礁石下边藏着一本书！\n\n"+
                   "突然有一只鲨鱼游了过来，将书吃到了肚子里！\n\n");
    
    fish=new(__DIR__"obj/shayu");
    book=new(__DIR__"obj/book");
    book->set("owner_ob",ob);
    book->move(fish);
    fish->set_status(ob);
    fish->move(environment(ob));
    fish->kill_ob(ob);
    return 1;
}