
inherit ROOM;

void create ()
{
        set ("short", "保仁堂");
        set ("long", @LONG
这是长安城一家老字号的药铺，相传原来的老板是皇宫中的御医，
手段可知一二。药铺中的摆设也十分考究，桌椅被勤快的伙计擦的干干
净净。墙上挂满了别人送来的谢匾。
LONG);

        
        set("exits", ([  
 "east" : __DIR__"xishidongjie1",
        ]));
   set("objects",([
		  __DIR__"npc/zhang":1,
		  ]));
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}


