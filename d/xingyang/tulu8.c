inherit ROOM;

void create()
{
	set("short", "土路");
	set("long", @LONG
这是一条尘土飞扬的大道，道面大约可以由四辆马车那样宽，这里
在向北走就是是河南的重镇荥阳，来往的车马行人不断，因为打仗的原
因所以路上会有一队队官兵经过，偶尔有骑马的官兵飞驰而过，带起一
片尘土。
LONG );

	set("exits", ([
               "east"      : __DIR__"tulu7",
               "northwest"      : __DIR__"tulu9",
		
	]));

 	set("outdoors", "xingyang");
	setup();
	replace_program(ROOM);
}



