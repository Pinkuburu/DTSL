
inherit ROOM;

void create()
{
        set("short", "天水");
        set("long", @LONG
这里是天水城所在地，从这里向北，就要进入丝绸之路了，所以城
市虽然小，但是却非常热闹，南来北往的客商纷纷在此做准备或者修整，
走在大街上看到的令人目不暇接。
LONG);
        set("outdoors", "tuyuhun");

        set("exits", ([
                "north" : __DIR__"silk12",
                "west" : __DIR__"shatulu2",
                "east" : "/d/changan/guandao5",
        ]));
  
        set("valid_startroom", 1);

        setup();
}

