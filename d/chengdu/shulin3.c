
inherit ROOM;
 void create()
{
       set("short", "热带雨林");
       set("long", @LONG
这是一片热带雨林。你已经到了雨林的内部，你不禁小心起来，据
说人是很容易在热带雨林中迷路的。
LONG);
       set("exits", ([
               "northeast" : __DIR__"shulin2",
               "southwest" : __DIR__"shulin4",
                    ]));

       setup(); 
       replace_program(ROOM);
}


