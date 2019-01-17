
inherit "/std/sboard.c";

int do_appoint(string arg);

void create()
{
        set_name("天策府英雄榜", ({ "yingxiong bang","bang" }) );
        set("location", "/d/cahc/tiancedian");
        set("board_id", "lifa_b");
        set("deadtimes",0);
        set("money",0);
        set("exp",0);
        set("long", "这是天策府英雄榜。\n" );
        seteuid(ROOT_UID);
        setup();
        set("capacity", 200);
       
}
int do_appoint(string arg)
{
   object me,ob;string name,hat;int i;
   me=this_player();
   if(!arg||sscanf(arg,"%s %s",name,hat)!=2)
   return notify_fail("请使用renming(appoint) 某人 某职务。\n");
   if(me->query("shili/leader")!="lifa_b")
   return notify_fail("你不是李阀的首领，没有这个权利！\n");
   if(!objectp(ob=present(name,environment(me))))
    return notify_fail("这里没有这个人。\n");
  
   if(ob->query("shili/name")!=me->query("shili/name"))
   return notify_fail("你和他不是一个势力，不能任命职务！\n");
   
   if(strlen(hat)>20)
   	return notify_fail("你眉头一皱，发现这个职务的名字实在太长了。\n");
   	
   ob->set("shili/guanzhi",hat);
   CHANNEL_D->do_channel(this_object(), "rumor",
   sprintf("李阀首领任命%s为%s!\n",ob->name(),hat));
   return 1;
} 