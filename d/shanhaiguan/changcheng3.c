// /d/gaoli/aikou
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "隘口");
	set("long", @LONG
这里是长城的一个隘口，秦朝连接长城，每隔数十里建造一个隘口
用来驻扎军队，这是长城最东的隘口，再向东你可以看见一个入海口那
就是老龙口。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("valid_startroom", 1);
set("exits", ([
	        "northeast" : __DIR__"changcheng2",
	        "west" : __DIR__"changcheng4",
            	"southdown" : "/d/yuyang/shandao4",
	]));
       setup();
	replace_program(ROOM);
}	
