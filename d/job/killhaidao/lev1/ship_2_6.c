/*
 * File    : ���� (/d/job/killhaidao/lev1/ship_2_6.c)
 * Author  : [1;36m�����[2;37;0m(yanyan@����˫��  )
 * Date    : Mon Mar 17 21:14:22 2003
 */
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "����");
        set("long", @LONG
��������һ�Ҹս��ɲ��õĴ󴬣����Դ������滹Ʈɢ��һ������
������ζ������ͣ����ˮ���ڴ�����ҴҾ�����
LONG
);
        set("exits",([
	"south" : __DIR__"ship_4_6",
	"west" : __DIR__"ship_2_4",
	"north" : __DIR__"ship_0_6",
	"east" : __DIR__"ship_2_8",
        ]));
        setup();
//        replace_program(ROOM);
}
