
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","商店篇");
  set ("long", @LONG
这里教会你如何在泥巴中买东西！首先你要到商店、小吃店或饭店
中，然后使用 list 命令看看能买到什么东西。
> list
你可以购买下列这些东西：
酱肘子                        (zhouzi)        八十文钱  
烤鸭                          (kaoya)         一两银子  
牛皮酒袋                      (jiudai)        二十文钱  
浇汁五味鱼                    (yu)            六两银子  

如果你想买“浇汁五味鱼”，使用  buy yu from 店主的名字就可以了。
当然，你要花上六两银子了！
LONG);

  set("exits", ([ 
 "west":__DIR__"room4",
        ]));
  
set("no_fight",1);
set("no_exert",1);
  set("valid_startroom", 1);
  setup();
 
}

