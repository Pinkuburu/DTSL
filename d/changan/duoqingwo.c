
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","多情窝");
  set ("long", @LONG
室雅何需大，“多情公子”侯西白在长安的这个小厅堂布置简雅，窗
明几静，最令整个环境充盈书香气息的是挂在东西壁间两对写得龙飞凤
舞、清丽高古的长对联。其中一副的上联是“ 放明月出山，快携酒于石
泉中，把尘心一洗。引董风入室，好抚琴在藕乡里，觉石骨都清。” 另
一联是“ 从曲径穿来，一带雨添杨柳色。好把疏帘卷起，半池风送藕花
香。”既相对称，且意境高远，令人读来心怀舒畅。
LONG);

  set("exits", ([ 
  "east":__DIR__"shibanlu",
        ]));
  set("valid_startroom", 1);
  setup();
 
}

