
inherit ROOM;
 void create()
{
       set("short", "庭院");
       set("long", @LONG
这里是李财主家的庭院。这里种植了各种花草。东面是李财主的卧
室，西面是个柴房。
LONG);
       set("outdoors", "成都");

       set("exits", ([
               "out" : __DIR__"door",
			   "east":__DIR__"woshi",
			   "west":__DIR__"chaifang",
                         
       ]));
	
       setup(); 
      
}

