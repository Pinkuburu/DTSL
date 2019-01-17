inherit ROOM;

void create()
{
	set("short", "黄河岸边");
	set("long", @LONG
这里是黄河的的岸边。你站在岸边的大堤上，面前黄河滚滚，气势
惊人。无风都有三尺浪，河水带着泥沙咆哮而过，你感觉大堤好象都在
震动。
LONG );

	set("exits", ([
              "west"      : __DIR__"huanghe2",
               "east"      : "/d/yangzhoubei/huanghenan",
		
	]));


 	set("outdoors", "pengliang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



