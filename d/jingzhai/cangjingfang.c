
#include <ansi.h>
inherit ROOM;

string do_action1();

void create ()
{
  set ("short",HIY"藏经房"NOR);
  set ("long", @LONG
这里是慈航静斋的藏经房。这里放着慈航静斋数代经书和收藏，全
都是佛家宝典。桌子上还放着一本书 (shu)，上面写着“慈航剑典”四
个字。这是慈航的上乘武学典籍，普通人看了不会有好处的。
LONG);

  set("exits", ([ 

  "east":__DIR__"wenzhitang",
   ]));
  set("objects",([
	  __DIR__"npc/dizi":1,
	  ]));
  set("item_desc",([
     "shu":(:do_action1:),
     ]));
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
   add_action("do_lingwu","lingwu");

}

int do_lingwu()
{
	
   object ob;
   string msg;
   
   ob=this_player();
   
   if(ob->query_skill("qingxin-force",1)<180)
   return notify_fail("你的清心普善诀修为太低了，无法领悟任何东西！\n");
   
   if(ob->query_skill("siguanfa",1)){
      
      if(ob->query_skill("siguanfa",1)>=300)
      return notify_fail("死关法已经领悟到极限，无法再提高了！\n");
      if(ob->query("potential")<=0)
      return notify_fail("你的潜能不足，无法领悟！\n");
      ob->improve_skill("siguanfa",ob->query("potential")*ob->query_int()*2/3);
      ob->set("potential",0);
      msg="$N心神合一，排除杂念，觉得死关法的修为有了提高！\n";
      message_vision(msg,ob);
      return 1;
   }
   if(ob->query_skill("sashoufa",1)){
      
      if(ob->query_skill("sashoufa",1)>=300)
      return notify_fail("撒手法已经领悟到极限，无法再提高了！\n");
      if(ob->query("potential")<=0)
      return notify_fail("你的潜能不足，无法领悟！\n");
      ob->improve_skill("sashoufa",ob->query("potential")*ob->query_int()*2/3);
      ob->set("potential",0);
      msg="$N心神合一，排除杂念，觉得撒手法的修为有了提高！\n";
      message_vision(msg,ob);
      return 1;
   }
      
   
   if(ob->query("PKS")>=5
     ||ob->query("deadtimes")>=2
     ||ob->query("execute_quest/cihang_fail")){
     return notify_fail("你的机缘不高，看来无法领会慈航中高级的心法了！\n");
   }
   if(random(100)>70){
     ob->set_skill("siguanfa",1);
     tell_object(ob,"你渐渐领悟到“剑心通明”的一点皮毛，但是觉得还有必要以后继续领会。\n"); 
   }
   else{
     ob->set_skill("sashoufa",1);
  ob->set("execute_quest/xinyoulingxi");
     tell_object(ob,"你突然感到气血翻腾，无法再领会下去了，看来你只能领悟到“心有灵犀”了！\n");
   }
   ob->set("cihang_menpai/cihang_MKS",ob->query("MKS"));
   ob->set("cihang_menpai/cihang_PKS",ob->query("PKS"));
   ob->set("cihang_menpai/cihang_deadtimes",ob->query("deadtimes"));
   
   return 1;
}


string do_action1()
{
  object ob;
  
  ob=this_player();
  
  if(ob->query("execute_quest/jianxintongming"))
  return "你已经领悟出了剑心通明。\n";
  if(ob->query("execute_quest/xinyoulingxi"))
  return "你已经领悟出了心有灵犀。\n";
  
  if( (ob->query_skill("siguanfa",1)<180
       &&ob->query_skill("sashoufa",1)<180)
      ||ob->query("family/cihang_xinfa_fail")
    ){
     ob->set("kee",0);
     ob->set("sen",0);
     ob->set("gin",0);
   return "你感到气血翻滚，不敢再看下去了！\n";
  }
  if( ob->query("MKS")!=ob->query("cihang_menpai/cihang_MKS")
    ||ob->query("PKS")!=ob->query("cihang_menpai/cihang_PKS")
    ||ob->query("deadtimes")!=ob->query("cihang_menpai/cihang_deadtimes")
    ||ob->query("age")>=50
    ||ob->query("couple")
    ){
    ob->set("family/cihang_xinfa_fail",1);
    return "你无法再将自己的心法提高一个层次！\n";
  }
  if(ob->query_skill("siguanfa",1)){
     ob->set("execute_quest/jianxintongming",1);
     return "你从慈航剑典中领悟出了剑心通明！\n";
  }
  if(ob->query_skill("sashoufa",1)){
     ob->set("execute_quest/xinyoulingxi",1);
     return "你从慈航剑典中领悟出了心有灵犀！\n";
  }
  return "这是一本慈航剑典。\n";
}
