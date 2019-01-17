
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","太常寺");
  set ("long", @LONG
太常寺本掌管朝廷宗庙礼仪，规范百姓风纪。后来隋唐近年来，民
间文化发展迅速，诗词歌舞越来越盛行，于是音乐，舞蹈等管理内
容也并入太常寺。
LONG);

  set("exits", ([ 
 "east":__DIR__"tianjie4",
        ]));
   
  
  set("valid_startroom", 1);
  setup();
 
}

