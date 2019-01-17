inherit ROOM;
void create()
{
	set("short", " 青石路");
	set("long", @LONG
这是一条青石路，街道宽敞而干净，青砖砌的路面被雨水冲得光明
如镜，街道两侧的瓦房高大而宏伟，双人合抱的杨树十步一株，整齐地
排在两边。北面一对大红灯笼，悬挂在朱门两旁。这里就是城守元帅府。
大街南面有几家店铺，街道有点冷清。
LONG );
	set("exits", ([
		"north" : __DIR__"gate",
		"west"  : __DIR__"liyang",
		"east"  : __DIR__"junying",
		"south":__DIR__"yanju",
	]));
	set("no_clean_up", 0);
	set("outdoors", "liyang");
	setup();
	replace_program(ROOM);
}
