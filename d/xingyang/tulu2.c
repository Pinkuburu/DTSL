inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ����������Ĵ���������Լ��������������������������
�����߾����Ǻ��ϵ����������������ĳ������˲��ϣ���Ϊ���̵�ԭ
������·�ϻ���һ�Ӷӹٱ�������ż���������Ĺٱ��ɳ۶���������һ
Ƭ������
LONG );

	set("exits", ([
               "north"  : __DIR__"tulu1",
               "east"  : __DIR__"tulu3",
	       "southwest"   : "/d/yangzhoubei/xiaoxi2",
	]));


 	set("outdoors", "xingyang");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}


