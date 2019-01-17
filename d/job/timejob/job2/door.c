
#include <ansi.h>
#include <job_money.h>
inherit ROOM;

#define TOTAL_TASK 25

int do_open();

string *rooms=({
"room1","room2","room3","room4","room5","room6","room7","room8","room9","room10",
"room11","room12","room13","room14","room15","room16","room17","room18","room19","room20",
"room21","room22","room23","room24","room25","room26","room27","room28","room29","room30",
"room31","room32","room33","room34","room35","room26","room37","room38","room39","room40",
"room41","room42","room43","room44","room45","room46","room47","room48","room49","room50",
});

string *dir=({"east","south","west","north"});

void create ()
{
  set ("short",HIB"大石门"NOR);
  set ("long", @LONG
这是草原上的一个大石门。门上刻着许多奇怪的图案，上面
有两个把手，看起来已经锈迹斑斑，似乎很久没有人进去了。据说
这里藏有了很多的宝物。
LONG);

  set("exits", ([ 
 "up":"/d/saiwai/caoyuan",
        ]));
  set("no_quit",1);
 
  setup();
 
}

void init()
{
	
  add_action("do_open","open");
}

string *swap_room=({});
string first_room;
string link_dir="";
string *temp_room_dir=({});

void clear_room()
{
   object room;
   object *ob;
   int i,j;
   
   for(i=0;i<sizeof(rooms);i++){
     room=load_object(__DIR__+rooms[i]);
     ob=all_inventory(room);
     for(j=0;j<sizeof(ob);j++){
     	if(ob[j]->is_character()&&userp(ob[j])){
       	tell_object(ob[j],"\n\n你看到有一群马贼拿着刀杀了过来，赶紧跑出了石门！\n\n");
        ob[j]->move(__DIR__"door");}
       else if(ob[j]->is_character()) destruct(ob[j]);}
       
     room->delete("exits");}
   return;
}

void set_job(object ob,string room_name)
{
   object killer,boss,*member,max_ob;
   int i;
   string room;
   
   max_ob=ob;
   member=ob->query_team();
   
   for(i=0;i<sizeof(member);i++){
   	if(member[i])
   	if(member[i]->query("combat_exp")>max_ob->query("combat_exp"))
   	 max_ob=member[i];}
   i=20+sizeof(member);
   while(i--){
   	room=rooms[random(sizeof(rooms))];
   	 killer=new(__DIR__"npc/killer");
        
     if(max_ob->query("combat_exp")>killer->query("combat_exp"))
     killer->set("combat_exp",max_ob->query("combat_exp")+500000);
     set_all_skill(killer,max_ob->query("max_pot")-90);
     copy_hp_item(max_ob,killer,"gin");
     killer->set("eff_kee",max_ob->query("max_kee")*3/2);
     killer->set("max_kee",max_ob->query("max_kee")*3/2);
     killer->set("kee",max_ob->query("max_kee")*3/2);
     copy_hp_item(max_ob,killer,"sen");
     if(max_ob->query("max_force")>killer->query("max_force")){
     	killer->set("max_force",max_ob->query("max_force")+2000);
     	killer->set("force",max_ob->query("max_force")+2000);}
     killer->move(__DIR__+room);}
     
     boss=new(__DIR__"npc/boss");
  if(max_ob->query("combat_exp")>boss->query("combat_exp"))
     boss->set("combat_exp",max_ob->query("combat_exp")+500000);
  set_all_skill(boss,max_ob->query("max_pot")-50);
     copy_hp_item(max_ob,killer,"gin");
     boss->set("eff_kee",max_ob->query("max_kee")*3/2+4000);
     boss->set("max_kee",max_ob->query("max_kee")*3/2+4000);
     boss->set("kee",max_ob->query("max_kee")*3/2+4000);
     copy_hp_item(max_ob,boss,"sen");
  if(max_ob->query("max_force")>boss->query("max_force")){
     	boss->set("max_force",max_ob->query("max_force")+4000);
     	boss->set("force",max_ob->query("max_force")+4000);}
   boss->move(__DIR__+room_name);
   return;
}
     	
int do_open()
{
   object ob,timerobot,*member;
   object room;
   string room_name;
   string *room_names;
   string temp_room;
   string *room_dirs;
   string room_dir;
   int i,j,k;
   
   ob=this_player();
   
   if(sizeof(ob->query_team())<=1)
   return notify_fail("你自己一个人去杀马贼，太危险了！\n");
   if(ob->query("combat_exp")<1000000)
   return notify_fail("你的经验太低了，去杀马贼太危险了！\n");
   
   member=ob->query_team();
   
   for(i=0;i<sizeof(member);i++)
      if(member[i]&&member[i]->query("combat_exp")<1000000)
       return notify_fail("你的队伍中"+member[i]->name()+"经验太低了！\n");
       
      
   for(i=0;i<sizeof(member);i++)
    if(member[i]&&environment(member[i])==environment(ob))
      member[i]->set_temp("timejob2_permit",1);
   
   timerobot=load_object("/d/job/timejob/timerobot");
   timerobot->restore();
   if(timerobot->query("tasks")<TOTAL_TASK)
   return notify_fail("石门现在打不开！\n");
   if(query("open_flag"))
   return notify_fail("石门已经打开了！\n");
   clear_room();
   room_dir="";
   room_names=rooms;
   i=sizeof(room_names);
   room_name=room_names[random(i)];
   first_room=room_name;
   room_names=room_names-({room_name});
   for(;sizeof(room_names)>0;){
               
      room_dirs=dir;
      if(sizeof(link_dir)>0)
      room_dirs=room_dirs-({link_dir});
      
      room=load_object(__DIR__+room_name);
           
      for(k=0;k<3&&sizeof(room_names)>0;k++){
      	
      room=load_object(__DIR__+room_name);
     
      
      room_dir=room_dirs[random(sizeof(room_dirs))];
      room_dirs=room_dirs-({room_dir});
      
      
      temp_room=room_names[random(sizeof(room_names))];
      room_names=room_names-({temp_room});
      swap_room=swap_room+({temp_room});
      
      room->set("exits/"+room_dir,__DIR__+temp_room);
      room=load_object(__DIR__+temp_room);
      room->delete("exits/out");
      if(room_dir=="east"){
      	room_dir="west";
        room->set("exits/west",__DIR__+room_name);}
      else
      if(room_dir=="west"){
      	room_dir="east";
        room->set("exits/east",__DIR__+room_name);}
      else
      if(room_dir=="south"){
      	room_dir="north";
        room->set("exits/north",__DIR__+room_name);}
      else
      {
      	room_dir="south";
        room->set("exits/south",__DIR__+room_name);}
      temp_room_dir=temp_room_dir+({room_dir});
      }
      j=random(sizeof(swap_room));
      room_name=swap_room[j];
      link_dir=temp_room_dir[j];
      temp_room_dir=({});
      swap_room=({});}
   set("exits/enter",__DIR__+first_room);
   room=load_object(__DIR__+first_room);
   room->set("exits/out",__DIR__"door");
   set("open_flag",1);
   set_job(ob,room_name);
   tell_object(environment(ob),HIB"\n只听嘎吱嘎吱几声，石门漏出了一个洞！\n\n"NOR);
   return 1;
}

int valid_leave(object ob,string dir)
{
    if(dir=="enter"&&!ob->query_temp("timejob2_permit"))
    return notify_fail("你进不去！\n");
    if(dir=="up")
     ob->delete_temp("timejob2_permit");
    return ::valid_leave(ob,dir);
}
      
      
      