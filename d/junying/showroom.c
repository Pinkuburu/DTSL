//校场,showroom.c
inherit ROOM;
void create()
{
set("short","校场");
set("long",@LONG
这里是华亭镇驻军的校场。华亭镇自古屡受海盗侵袭，加之盗贼猖狂，
朝廷故设华亭驻军，命将军张天恩围剿匪众，协助治安，校场上沙尘滚滚，
遮天蔽日，官兵们正演练武艺。当中观演台上，正坐一员大将，双目炯炯，
观看士兵操练。东南方是兵营所在。西边是关押贼人之处。东边是兵器库。
LONG);
set("exits",([
"up":__DIR__"watchroom",
"west":__DIR__"laogate",
"east":__DIR__"wqgate",
"southeast":__DIR__"bingying",
]));
set("objects",([
__DIR__"npc/bing":4,
]));
setup();
}
