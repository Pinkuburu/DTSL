
inherit ROOM;
void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路，蜿蜒曲折。前面似乎有一个破庙。两旁的杂草非
常茂盛，一阵风吹来，杂草好象波浪般地上下翻涌。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"xiaolu1",
 "north":__DIR__"xiaolu3",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
