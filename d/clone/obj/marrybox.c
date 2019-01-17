
inherit ITEM;
#include <ansi.h>
string go_msg=HIY"只见半空中落下一位仙子，身着"+HIW+"霓裳羽衣"+HIY+"，朝两位夫妇微微一笑，\n"+
                 "拿起礼物箱，转身投入半空的"+HIC+"彩云"+HIY+"之中，飘遥而去。\n"NOR;

int do_qu(string arg);
int do_withdraw();

void create()
{
   set_name(HIR"礼物箱"NOR,({ "box"}) );  	
   set("long", "这是送给新婚夫妇的礼物箱。\n"+
               "你可以从这里边拿出兵器[qu]、\n"+
               "也可以拿出100两黄金[withdraw]。\n");
   set_weight(10);       
   set("unit","个");
   set("rumor",1);
   set("no_sell",1);
   set("value",100000000);
   setup();
 
}

int is_get_of(object pal,object ob)
{
  return notify_fail("这个东西不能拿起来。\n");
}
void init()
{
   add_action("do_qu","qu");
   add_action("do_withdraw","withdraw");
   
}

int do_qu(string arg)
{
  object ob;
  object weapon;
  string wp,type;
  
  ob=this_player();
  if(query("weapons")>=2)
  return notify_fail("你只能取两件兵器。\n");
  if(!arg||sscanf(arg,"%s %s",wp,type)!=2)
  return notify_fail("请使用 qu 兵器的名字 类型,\n名字可以加入颜色控制字符。\n");
  
  weapon=new("/obj/weaponclass/"+type);
	wp=replace_string(wp,"$HIR$",""HIR"");
	wp=replace_string(wp,"$HIG$",""HIG"");
	wp=replace_string(wp,"$HIY$",""HIY"");
	wp=replace_string(wp,"$HIW$",""HIW"");
	wp=replace_string(wp,"$HIB$",""HIB"");
	wp=replace_string(wp,"$HIM$",""HIM"");
	wp=replace_string(wp,"$HIC$",""HIC"");
	wp=replace_string(wp,"$GRN$",""GRN"");
	wp=replace_string(wp,"$RED$",""RED"");
	wp=replace_string(wp,"$BLK$",""BLK"");
	wp=replace_string(wp,"$YEL$",""YEL"");
	wp=replace_string(wp,"$BLU$",""BLU"");
	wp=replace_string(wp,"$MAG$",""MAG"");
	wp=replace_string(wp,"$CYN$",""CYN"");
	wp=replace_string(wp,"$WHT$",""WHT"");
	wp=wp+NOR;
	weapon->set("name",wp);
	weapon->set("long","这是一"+weapon->query("unit")+
	   ob->name()+"和"+ob->query("couple/couple_name")+"结婚所获得的礼物。\n");
	weapon->set("weapon_prop/damage",100);
	weapon->set("max_strong",100);
	weapon->set("strong",100);
	weapon->set("flag",0);
	weapon->move(ob);
	add("weapons",1);
	add("parents",1);
	message("vision",HIG"【大唐姻缘】："+ob->name()+HIG+"从礼物箱中拿出了一"+weapon->query("unit")+
	        weapon->name()+"\n"NOR,users());
	if(query("parents")>=3){
	message("vision","\n\n"+go_msg,users());
	destruct(this_object());
	return 1;}
	return 1;
}

int do_withdraw()
{
  object ob,money;
  ob=this_player();
  if(query("money"))
  return notify_fail("里面已经没有钱了。\n");
  money=new("/obj/money/gold");
  money->set_amount(100);
  money->move(ob);
  message("vision",HIG"【大唐姻缘】："+ob->name()+HIG+"从礼物箱中拿出了"+HIY+"一百两黄金。\n"NOR,users());
  add("parents",1);
  set("money",1);
  if(query("parents")>=3){
	message("vision","\n\n"+go_msg,users());
	destruct(this_object());
	return 1;}
  return 1;
}
