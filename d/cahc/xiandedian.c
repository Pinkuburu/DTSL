#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","显德殿");
  set ("long", @LONG
这里就是李建成在皇宫的住所，黄琉璃瓦重檐庑殿顶，室内东侧两
间隔出为暖阁，作为居住的寝室，门的西侧四间设南、北、西三面炕，
作为祭神的场所。与门相对后檐设锅灶，作杀牲煮肉之用。由于是皇家
所用，灶间设棂花扇门，浑金毗卢罩，装饰考究华丽。
LONG);

  set("exits", ([ 
 "north":__DIR__"chongjiaodian",
 "southdown":__DIR__"xiandemen",
        ]));
  set("objects",([
	  "/d/changan/npc/lijiancheng":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}

