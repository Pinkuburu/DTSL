
inherit ROOM;

 void create()
{
       set("short", "草地");
       set("long", @LONG
你突然发现热带雨林中还有这么美丽的地方。旁边是一条小溪，而
你正走在一片青草地上。这里的阳光温和，空气清新，真是人间的仙境
一般。
LONG);
       set("exits", ([
               "west" : __DIR__"caodi3",
			   "out":__DIR__"shulin4",
                  ]));
	   
       setup(); 
      
}

