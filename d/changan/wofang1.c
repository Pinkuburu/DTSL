
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Է�");
  set ("long", @LONG
������Ƕ�����ջ���Է��ˣ��Աߵ��Է��ڴ���������������Ҳ����
������������������Ϣһ���ˡ�
LONG);

  set("exits", ([ 
 "down":__DIR__"donglaikezhan",
 
        ]));
  set("sleep_room",1); 
  set("valid_startroom", 1);
  setup();
 
}
int valid_leave(object me,string dir)
{
	if(dir=="down")
		me->delete_temp("gived_money");
	return ::valid_leave(me,dir);
}