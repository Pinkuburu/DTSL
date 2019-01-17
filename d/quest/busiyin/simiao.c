
inherit ROOM;
void create ()
{
  set ("short","大殿");
  set ("long", @LONG
这里寺庙的正殿。面前的佛像已经破旧不堪，没有了面目。到处是
破桌子、破椅子，还有行人生火做饭留下的焦碳。一阵风吹来，只有几
个破旧的佛幡还在呼啦啦的响着，给人一种悲凉的氛围。
LONG);

  set("exits", ([ 
 "out":__DIR__"door",
        ]));
  set("objects",([
     __DIR__"pishou-xuan":1,
     __DIR__"anlong":1,
     __DIR__"youniao-juan":1,
     __DIR__"zuoyou-xian":1,
     ]));
  set("valid_startroom", 1);
  setup();
 
}
