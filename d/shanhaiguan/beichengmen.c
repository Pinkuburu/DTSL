// /d/gaoli/beimennei
// Room in 山海关
// rich 99/04/05
// modify by yang

inherit ROOM;
void create()	
{
	set("short", "北城门");
	set("long", @LONG
这里是山海关的北城门，你抬头望去只看见「天 下 第 一 关」五
个斗大的字，山海关是出入关的咽喉，以前有重兵把守，现在天下大乱
这里成了三不管地界，南面就到了城中，北面是出关的大道，通向高丽
和东突厥。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : "/d/saiwai/road1",
		"south" : __DIR__"beidajie",
	        "eastup" : __DIR__"chengqiangshang3",
            	"westup" : __DIR__"chengqiangshang4",
	]));
 set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
       setup();
	replace_program(ROOM);
}
