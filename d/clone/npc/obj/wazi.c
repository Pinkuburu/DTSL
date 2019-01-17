
#include <ansi.h>
inherit ITEM;

int do_action(string arg);

void create()
{
   set_name(HIC"圣诞"HIG"袜子"NOR, ({ "wa zi","zi"}) );
   set_weight(150);
   
     set("material", "布");
     set("unit", "双");
     set("value",100);
     set("no_give",1);
     set("no_drop",1);
     set("no_get",1);
     set("no_sell",1);     
   
   setup();
}

string long()
{
   
   return this_player()->name()+"你好！祝您"HIY"圣诞节"NOR"快乐！\n"+
          "感谢你对"HIC"大唐双龙"NOR"的支持！\n"+
          "近期网络线路不断出现故障，还希望能够得到您的理解！\n"+
          "这是一双圣诞袜子，如果你穿上它，就会得到圣诞节的礼物。\n"+
          HIG"（chuan wa zi）\n"NOR;
       
}

void init()
{
  add_action("do_action","chuan");
}

int do_action(string arg)
{
   object ob;
   ob=this_player();
   
   if(!arg)
   return 0;
   if(!present(arg,ob))
   return 0;
   if(!id(arg))
   return 0;
   
   if(query("owner_ob")!=ob)
   return notify_fail("这个袜子不是你的，你不能穿。\n");
   
   tell_object(ob,"\n突然远处传来热闹的声音，你连忙朝那里看过去... ...\n\n");
   write(@LONG
   
   [1;32m 只听砰地一声，一个圣诞礼花冲上了天空！[2;37;0m 
   
   [5m[1;32m
   ★°∴°°∴ ☆°．·★°∴°．
         ◢◣        ◢◣圣诞节来临了哦~
        ◢★◣      ◢★◣  
       ◢■■◣    ◢■■◣ ．·°∴★°．°∴°．☆° ．·°
      ◢■■■◣  ◢■■■◣ 祝你圣诞节快乐！
      ︸︸||︸︸!!︸︸||︸︸°．°★ ．·°∴°°．★☆°
               .  [2;37;0m   
LONG);
   
   ob->add("potential",800);
   ob->add("food",1000);
   ob->add("water",1000);
   
   tell_object(ob,query("name")+"里突然冒出一阵浓烟，一时间你犹如飞翔在云雾之中。\n"+
                  "烟雾消散，"+query("name")+"已经消失了。\n");
   
   destruct(this_object());
   return 1;
}