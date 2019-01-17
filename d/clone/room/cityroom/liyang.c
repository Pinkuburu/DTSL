
inherit "/std/orgroom/cityroom.c";


void create ()
{
  set ("short","黎阳府衙");
  set ("long", @LONG
这里是黎阳的府衙，谁占领了这里，也就意味着占领了黎阳城。这
里戒备森严，有许多官兵在这里把守。占领城市后可以定期增加自己帮
会的贮备，因此这里也是经常战火不断。
LONG);
  
  set("city_id","liyang");
  set("city_name","黎阳");
  set("valid_startroom", 1);  
  set("owner","wizard");
  set("lev1_guard",1);
  set("max_person",2000);
  set("person",500);
  set("city_type","小");
  restore();
  set("check_victory",0);
  set("exits",([
   "south":"/d/liyang/gate",
  
  ]));
 
  setup();
  save();
  
 
}
