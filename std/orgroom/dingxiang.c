
inherit __DIR__"cityroom.c";


void create ()
{
  set ("short","定襄府衙");
  set ("long", @LONG
这里是定襄的府衙，谁占领了这里，也就意味着占领了定襄城。这
里戒备森严，有许多官兵在这里把守。占领城市后可以定期增加自己帮
会的贮备，因此这里也是经常战火不断。
LONG);
  
  set("city_id","dingxiang");
  set("city_name","定襄");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",5000);
  set("person",1000);
  set("city_type","中等");
  restore();
  set("check_victory",0);
  set("exits",([
   "east":"/d/dingxiang/huanggong",
  
  ]));
 
  setup();
  save();
  
 
}
