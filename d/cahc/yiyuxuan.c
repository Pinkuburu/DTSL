
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","宜雨轩");
  set ("long", @LONG
宜雨轩位于西内苑西，利用原本的自然环境建成一组园林院落，雅
致清幽，与皇宫其他殿院相比，多出一份清新的气息。主建筑设在南端，
北部叠湖设石山，其上有曲折小桥，人工湖来至厅堂处，转化为曲曲溪
流，点缀以奇石。水流绕轩西侧流入轩南的扇形湖，造成湖水泊岸的荡
漾效果，颇有原野意境，把水和建筑物的关系处理得异常出色，显是出
于高手构思。住在这里的便是大唐公主李秀宁。
LONG);

  set("exits", ([ 
 "east":__DIR__"xineiyuan",
 
        ]));
  set("objects",([
          "/d/cahc/npc/lixiuning":1,
          ]));
  set("valid_startroom", 1);
  setup();
 
}

