
inherit ROOM;
 void create()
{
       set("short", "卧室");
       set("long", @LONG
这里是李财主的卧室。这里被褥整洁，看来是刚有人打扫过了。屋
子里供奉着一个财神象，香气缭绕。
LONG);
       set("outdoors", "成都");

       set("exits", ([
               "west" : __DIR__"tingyuan",
			            
       ]));
	
       setup(); 
      
}

