// /d/zhuojun/xiaoxiang.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "翟府");
	set("long", @LONG
这里是翟娇的府邸，只见门卫森严，不时有江湖人物出入，门庭热
闹，显见翟娇在乐寿非常吃得开。
LONG
	);
set("outdoors", "/d/zhuojun");
set("exits", ([
                "west"  :__DIR__"beidajie1",
	]));
	
      set("objects",([
            "/d/job/questjob/npc/zhaijiao":1,
            ]));
       setup();
	replace_program(ROOM);
}	
