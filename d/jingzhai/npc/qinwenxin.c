
inherit "/std/lmaster.c";

#include <ansi.h>

void create()
{
   set_name("秦文心",({ "qin wenxin","qin" }) );
   set("gender", "女性" );
   set("age", 25);
   set("long", "这是慈航静斋的秦文心，负责传授慈航弟子\n"+
   						"初级的文化知识。\n");
       
   set("combat_exp",100000);
   set("int", 25);
   set("per", 26);
   set("max_gin",1000);
   set("max_kee",1000);
   set("max_sen",1000);
   set("max_force",1000);
   set("force",1000);
    
   set_skill("literate",80);   
  
   create_family("慈航静斋",7,"弟子");
   setup();
   carry_object(__DIR__"obj/baiyi")->wear();
  
}

