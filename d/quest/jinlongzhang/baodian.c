
inherit ROOM;


void create ()
{
  set ("short","大熊宝殿");
  set ("long", @LONG
这里就是回龙寺的大熊宝殿，正面供奉着如来佛祖，在地上还放了
几个蒲团。头的正上放挂着一面大铜钟。有几个僧人正在那里颂经念佛。
LONG);

  set("exits", ([ 

  "out":__DIR__"huilongsi",
  "south":__DIR__"wu1",
     ]));

  set("objects",([
    __DIR__"zhuchi":1,
    ]));
  set("valid_startroom", 1);
  setup();
 
}


