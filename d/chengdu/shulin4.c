
inherit ROOM;
int do_zuan(string arg);
 void create()
{
       set("short", "热带雨林");
       set("long", @LONG
这是一片热带雨林。你已经到了雨林的内部，你不禁小心起来，据
说人是很容易在热带雨林中迷路的。你仔细看了看，这里好象有一个洞。
LONG);
       set("exits", ([
               "northeast" : __DIR__"shulin3",
                  ]));
       set("item_desc",([
		   "hole":"这是一个洞,你似乎可以钻进去\n",
	   ]));
       setup(); 
      
}

void init()
{
	add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{   
    object me;
	me=this_player();
	if(!arg||arg!="洞") return notify_fail("你要干什么?\n");
    message_vision("$N看了看,然后朝洞里钻去\n",me);
	me->move(__DIR__"caodi2");
	return 1;
}
