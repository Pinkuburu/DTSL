
inherit ROOM;
void create ()
{
  set ("short","小路");
  set ("long", @LONG
这里是一条小路，蜿蜒曲折。前面有一个破庙，看起来已经很久没
有人住了。风一吹，老远就可以听见木门嘎吱嘎吱的声音。
LONG);

  set("exits", ([ 
 "enter":__DIR__"door",
 "south":__DIR__"xiaolu2",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
