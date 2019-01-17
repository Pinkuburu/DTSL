
inherit ROOM;
#include <ansi.h>
string give_msg();
void create()
{
	set("short", "船舱");
	set("long", @LONG
这里是船舱。这里的摆设不是很豪华，但是仍然不落俗套。清新典
雅，落落大方。这里挂着一个大牌子(pai)，看来是给东溟派弟子看的。
LONG);
	set("exits", ([
		"out":__DIR__"chuan",
		]));
	set("objects",([
		"/d/clone/npc/jiandingman":1,
		]));
	set("item_desc",([
	  "pai":(:give_msg:),
	  ]));
      set("valid_startroom", 1);   
	setup();
       
       
}

string give_msg()
{
  object ob;
  ob=this_player();
  if(ob->query("family/family_name")!="东溟派")
  return "上面模糊不清，看不出来有什么字迹。\n";
  return "由于在中原的生意已经完成，所以我回到东溟岛了，\n"+
         "耽误了东溟初级弟子的学习真是抱歉！请各位弟子到\n"+
         "东溟岛的"+HIG+"[青竹亭]"+NOR+"找我。\n\n"+
         "                                        "+HIW+"单青\n"NOR;
}
