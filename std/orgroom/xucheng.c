
inherit __DIR__"cityroom.c";


void create ()
{
  set ("short","许城府衙");
  set ("long", @LONG
这里是许城的府衙，谁占领了这里，也就意味着占领了许城城。这
里戒备森严，有许多官兵在这里把守。占领城市后可以定期增加自己帮
会的贮备，因此这里也是经常战火不断。
LONG);
  
  set("city_id","xucheng");
  set("city_name","许城");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",2000);
  set("person",700);
  set("city_type","小");
  restore();
  set("check_victory",0);
  set("exits",([
   "west":"/d/xucheng/houqiang",
  
  ]));
  setup();
  save();
  
 
}
