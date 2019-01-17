
inherit ROOM;
void create ()
{
  set ("short","庙门");
  set ("long", @LONG
这里寺庙的门前。庙门上的牌匾已经看不清楚了，上面已经长满了
杂草，还有鸟在上面做了窝。寺庙的墙壁已经大部分坍塌，显出荒凉的
气氛。
LONG);

  set("exits", ([ 
 "enter":__DIR__"simiao",
 "out":__DIR__"xiaolu3",
        ]));
  set("valid_startroom", 1);
  setup();
 
}
