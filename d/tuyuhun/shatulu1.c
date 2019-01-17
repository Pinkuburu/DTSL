inherit ROOM;

void create()
{
        set("short", "沙土路");
        set("long", @LONG
这是一条并不太好走的沙土路，向西就要进入沙漠地区了，行人很
少，只是偶尔会看见一些商旅和骆驼队。
LONG
        );
        set("exits", ([
          "northwest" : __DIR__"qinghaihu",
          "east" : __DIR__"shatulu2",
        ]));

        set("outdoors", "tuyuhun");
        set("valid_startroom", 1);
        setup();
        replace_program(ROOM);
}
