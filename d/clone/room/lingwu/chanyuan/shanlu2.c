inherit ROOM;
void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是静念禅院后山的山路。这里的地势越来越陡，随着山
势的增高，你的心跳不禁加快。
LONG);

  set("exits", ([ 
 "southdown":__DIR__"shanlu",
 "enter":__DIR__"room",
        ]));
 set("valid_startroom", 1);
  setup();
}