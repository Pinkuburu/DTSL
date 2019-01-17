// /d/gaoli/nanmennei
// Room in 山海关
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "南城门");
	set("long", @LONG
这里是山海关的南城门，你抬头望去只看见[33m天 下 第 一 关[0m五
个斗大的字，山海关是出入关的咽喉，以前有重兵把守，现在天下
大乱这里成了三不管地界，北面就到了城中，南面是入关的大道，
通向河北和山东。
LONG
	);
set("outdoors", "/d/shanhaiguan");
set("exits", ([
		"north" : __DIR__"nandajie",
		"south" : __DIR__"dadao2",
	        "eastup" : __DIR__"chengqiangshang1",
            	"westup" : __DIR__"chengqiangshang2",
                "southeast":"/d/yangzhoubei/haibin1"
	]));
 set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang":1,
	]));
       setup();
	replace_program(ROOM);
}
