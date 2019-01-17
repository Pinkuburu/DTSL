inherit ROOM;

void create()
{
	set("short", "黄河岸边");
	set("long", @LONG
这里是黄河的的岸边。你站在岸边的大堤上，面前黄河滚滚，气势
惊人。无风都有三尺浪，河水带着泥沙咆哮而过，你感觉大堤好象都在
震动。你的背后，是一面陡峭的山崖，一直向上延伸到云雾里，仔细倾
听，偶尔能听到“啊－啊 啊啊”的叫声，好像有人在山崖上高喊。
LONG );

	set("exits", ([
              "west"      : __DIR__"huanghe1",
               "east"      : __DIR__"huanghe3",
		
	]));


 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



