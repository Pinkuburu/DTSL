// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "城中心");
	set("long", @LONG
马邑是西北的重镇，刚开始这里就是一个兵营，百姓害怕突厥侵犯，
就迁移到这儿来，就逐渐形成现在的规模，所以就形成现在这样的，商铺
和住户多在南面。
LONG);
set("outdoors", "/d/mayi");
set("exits", ([
                "north": __DIR__"beimen", 
                "south": __DIR__"nanjie",
                "east" : __DIR__"dongjie", 
                "west" : __DIR__"xijie",
                "northeast":"/d/clone/room/cityroom/mayi",  
	]));
set("objects",([
  __DIR__"npc/zuihan":1,
  ]));
       setup();
	replace_program(ROOM);
}	
