
inherit ROOM;

 void create()
{
       set("short", "草地");
       set("long", @LONG
这里是一片青草地，旁边是一条小溪。西边看来是有不少的树木，
那里群峰耸立，看起来非常险峻。
LONG);
       set("exits", ([
               "east":__DIR__"caodi2",
               "westup":__DIR__"shijie1",
                  ]));
 if(sizeof(children(__DIR__"obj/xuantie"))<5)
       set("objects",([
       __DIR__"obj/xuantie":1,
       ]));
       setup(); 
      
}

