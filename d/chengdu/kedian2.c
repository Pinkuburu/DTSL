
inherit ROOM;

void create()
{
	set("short", "客店二楼");
	set("long", @LONG
你正走在客店二楼的走廊上，可以听到从客房里不时地呼呼的打酣
声，一阵高过一阵。不时有睡意朦胧的旅客进进出出，到楼下的掌柜处
付了钱再上来睡觉。
LONG);

	set("exits", ([
		"down" : __DIR__"kedian",
	]));

set("sleep_room",1);
	setup();
	
}
int valid_leave(object ob,string dir)
{
  if(dir=="down")
  ob->delete_temp("rent_paid");
  return ::valid_leave(ob,dir);
}
