
inherit ROOM;
 void create()
{
       set("short", "草地");
       set("long", @LONG
这里是片草地。湿润的空气扑鼻而来。从这里可以听到水流的声音。
有几只野兔从你的身旁跳过。
LONG);
       set("exits", ([
               "north" : __DIR__"tulu1",
               "southwest" : __DIR__"jiangan1",
                    ]));

       setup(); 
       replace_program(ROOM);
}


