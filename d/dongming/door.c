
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", GRN"碧宵宫"NOR);
	set("long", @LONG
这里是碧宵宫的门口。这里就是进出东溟派的出口。东溟派在海外
享有很高的声誉，尤其是他们的打造兵器的技术，更是无人能比。
LONG);
	set("exits", ([
	     
		"southup" :__DIR__"shijie1",
		"north":__DIR__"shulin1",
		
	]));
	set("objects",([
		__DIR__"npc/dizi":2,
		]));
    set("valid_startroom", 1);   
       set("outdoors", "青石路");  
	setup();
        "/obj/board/party_dm_b.c"->foo();
       
}
int valid_leave(object me,string dir)
{
	object ob;
	if(dir=="southup"&&
		me->query("family/family_name")=="阴癸派"
		&&objectp(ob=present("nv dizi",environment(me))))
	{ message_vision("$N冲着$n叫道：你这是来送死！\n",ob,me);
	  ob->kill_ob(me);
	  return notify_fail("你被拦住了！\n");
	}
	return ::valid_leave(me,dir);
}

