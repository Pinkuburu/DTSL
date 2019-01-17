
#include <ansi.h>

inherit ITEM;
int do_wear(string arg);
int do_unwear(string arg);
void create()
{
   set_name(HIB"人皮面具"NOR, ({ "mask"}) );
   set_weight(20);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("material", "paper");
	 set("long","这是一个精心制作的人皮面具，样子看起来好象早已退隐江湖的[霸刀]岳山。\n");
     set("unit", "个");
   
   }
   setup();
}

void init()
{
	add_action("do_wear","wear");
	add_action("do_unwear","unwear");
}

int do_wear(string arg)
{
	object ob;
	ob=this_player();
	if(!arg||arg!="mask")
		return notify_fail("你要戴什么？\n");
	if(query("weared"))
	return notify_fail("你已经戴上面具了。\n");
	message_vision("$N拿出人皮面具戴在了头上。\n",ob);
	set("no_give",1);
	set("no_drop",1);
	set("no_sell",1);
	set("no_steal",1);
	set("weared",1);
    ob->set_temp("apply/name",({"岳山"}));
	//ob->set_temp("apply/id",({"yue shan"}));
	//ob->set_temp("apply/short",({"岳山"}));
	ob->set_temp("apply/long",({"这就好象是早已退隐江湖多年的岳山\n"}));
	return 1;
}

int do_unwear(string arg)
{
	object ob;
	ob=this_player();
	if(!arg||arg!="mask")
		return notify_fail("你要脱掉什么？\n");
	if(!query("weared"))
	return notify_fail("你没有戴上面具。\n");
	message_vision("$N从脸上摘下人皮面具，揣回衣中。\n",ob);
	delete("no_give");
	delete("no_drop");
	delete("no_sell");
	delete("no_steal");
	delete("weared");
	//ob->delete_temp("apply/short");
	ob->delete_temp("apply/name");
	ob->delete_temp("apply/long");
	//ob->delete_temp("apply/id");
	return 1;
}