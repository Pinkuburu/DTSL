// /d/gaoli/aikou
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "衙门大门");
        set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回”的牌
子分放两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。
几名衙役在门前巡逻。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
	        "east" : __DIR__"guangchang",
            	"west" : __DIR__"yamendating",
	]));
       setup();
	replace_program(ROOM);
}
