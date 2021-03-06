/*
巫师地址簿。
请是用helpbu来看帮助。
written by yanyan.
*/
inherit ITEM;
inherit F_SAVE;
#include <ansi.h>

int do_add(string arg);
int do_edit(string arg);
int do_list(string arg);
int do_discard(string arg);
int do_help();
void do_edit_count(string arg,object ob,mapping *counts,int i,string msg);
string query_save_file()
{
  return "/data/yanyan_homework_box";
}
void create()
{
	set_name(HIY"巫师地址簿"NOR,({ "bu"}) );  	
   	set("long", "这是巫师地址簿，具体用法请使用helpbu查看。\n");
   	set_weight(10);       
   	set("unit","个");
   	set("value",100000000);
   	setup();
   	restore();
 
}

int is_get_of(object pal,object ob)
{
	return notify_fail("这个东西不能拿起来。\n");
}
void init()
{
	add_action("do_help","helpbu");
   	add_action("do_add","addcount");
   	add_action("do_edit","editcount");
   	add_action("do_list","listcount");
   	add_action("do_discard","delcount");
   
}

int do_add(string arg)
{
	object ob;
	mapping *counts;
	mapping newcount;
   	int num,i;
   	ob=this_player();
   	if(!wizardp(ob))
   	return 0;
   	if(!arg) return notify_fail("请输入要添加的ID。\n");

   	counts=query("counts");
   	num=sizeof(counts);
   	for(i=0;i<sizeof(num);i++){
      	if(counts[i]["id"]==arg) break;
    }
   	if(i<sizeof(num))
   		return notify_fail("这个帐号已经添加了，如果要编辑，请使用editcount。\n");
   	newcount=allocate_mapping(6);
   	newcount["id"]=arg;
   	newcount["e-mail"]="none";
   	newcount["oicq"]="none";
   	newcount["tel"]="none";
   	newcount["hand_tel"]="none";
   	newcount["call"]="none";
   	if(counts)
   		counts+=({newcount});
   	else 
   		counts=({newcount});
   	set("counts",counts);
   	save();
   	tell_object(ob,arg+"这个帐号添加完毕，如果需要添加具体内容，请使用editcount。\n");
   	return 1;
}

int do_edit(string arg)
{
	object ob;
  	mapping *counts;
  	int num,i;
  	
  	ob=this_player();
   	if(!wizardp(ob))
   		return 0;
  	if(!arg)
  		return notify_fail("你要编辑什么帐号？\n");

  	counts=query("counts");
  	num=sizeof(counts);
  	for(i=0;i<num;i++)
   		if(counts[i]["id"]==arg) break;
  	if(i==num)
  		return notify_fail("没有这个帐号！\n");
  	if(counts[i]["email"]){
  		write("目前"+arg+"这个帐号的E-MAIL是："+counts[i]["e-mail"]+"\n"+
        		"需要更改吗？如果需要，请直接输入新的E-MAIL，不需要，请输入n(N)\n");
  		input_to("do_edit_count",ob,counts,i,"e-mail");
  		return 1;
  	}
  	else{
  		write("目前"+arg+"这个帐号没有E-MAIL，\n"+
        		"需要更改吗？如果需要，请直接输入新的E-MAIL，不需要，请输入n(N)\n\n输入:");
  		input_to("do_edit_count",ob,counts,i,"e-mail");
  		return 1;
  	}
}

string new_string(string msg)
{
  	switch(msg){
  
  		case "e-mail":return "oicq";
  		case "oicq": return "tel";
  		case "tel": return "hand_tel";
  		case "hand_tel": return "call_tel";
  		case "call_tel": return "over";
  		default: return "over";
  	}
}

string swap_chinese(string msg)
{
  	switch(msg){
  
  		case "e-mail":return "电子邮件";
  		case "oicq": return "oicq";
  		case "tel": return "电话";
  		case "hand_tel": return "手机";
  		case "call_tel": return "传呼";
  		default: return "错误";
  	}
}

void do_edit_count(string arg,object ob,mapping *counts,int i,string msg)
{
	string newmsg;
	
   	newmsg=new_string(msg);
   	
	if((arg=="n"||arg=="N")&&newmsg!="over"){
    	write(swap_chinese(msg)+"没有更改。\n\n");
    	write("目前这个帐号的"+swap_chinese(newmsg)+"是："+counts[i][newmsg]+"\n"+
        		"需要更改吗？如果需要，请直接输入新的"+swap_chinese(newmsg)+"，不需要，请输入n(N)\n输入:");
        input_to("do_edit_count",ob,counts,i,newmsg);
        return;
    }
	counts[i][msg]=arg;
   	write("更改"+swap_chinese(msg)+"为："+arg+"\n");
   	if(newmsg=="over"){
    	set("counts",counts);
    	save();
    	write("帐号更改完毕！\n");
    	return;
    }
   	write("目前这个帐号的"+swap_chinese(newmsg)+"是："+counts[i][newmsg]+"\n"+
        		"需要更改吗？如果需要，请直接输入新的"+swap_chinese(newmsg)+"，不需要，请输入n(N)\n输入:");
	input_to("do_edit_count",ob,counts,i,newmsg);
	return;
}

int do_list(string arg)
{
	object ob;
   	mapping *counts;
   	int num,i;
	string msg;
	
   	ob=this_player();
   	if(!wizardp(ob)) return 0;

   	counts=query("counts");
   	num=sizeof(counts);
   	if(num==0) return notify_fail("目前没有任何联系地址。\n");
   	msg="━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
   	if(!arg){
    	for(i=0;i<num;i++){
     		msg +="ID:"+counts[i]["id"]+"\n";
     		msg +="电子邮件:"+counts[i]["e-mail"]+"\n";
     		msg +="OICQ:"+counts[i]["oicq"]+"\n";
     		msg +="手机:"+counts[i]["hand_tel"]+"\n";
     		msg +="电话:"+counts[i]["tel"]+"\n";
     		msg +="传呼:"+counts[i]["call_tel"]+"\n\n\n";
     	}
		msg +="━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
     	ob->start_more(msg);
     	return 1;
    }
	for(i=0;i<num;i++){
		if(counts[i]["id"]==arg) break;
	}
	if(i==num)
		return notify_fail("目前地址簿中没有此帐号，请使用addcount添加此帐号！\n");
	msg +="ID      :"+counts[i]["id"]+"\n";
	msg +="电子邮件:"+counts[i]["e-mail"]+"\n";
	msg +="OICQ    :"+counts[i]["oicq"]+"\n";
	msg +="手机    :"+counts[i]["hand_tel"]+"\n";
	msg +="电话    :"+counts[i]["tel"]+"\n";
	msg +="传呼    :"+counts[i]["call_tel"]+"\n\n\n";
	msg +="━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
	ob->start_more(msg);
	return 1;
}

int do_discard(string arg)
{
  object ob;
  mapping *counts;
  int num,i;
  
  ob=this_player();
  if(!wizardp(ob))
  return 0;
  restore();
  counts=query("counts");
  num=sizeof(counts);
  if(!arg)
  return notify_fail("你要删除谁的地址？\n");
  if(num==0)
  return notify_fail("地址簿是空的！\n");
  for(i=0;i<num;i++)
   if(counts[i]["id"]==arg) break;
  if(i==num) 
  return notify_fail("没有这个帐号！\n");
  
  counts=counts[0..i-1]+counts[i+1..num-1];
  set("counts",counts);
  save();
  write("从地址簿中清除了"+arg+"的地址！\n");
  return 1;
}

int do_help()
{
  object ob;
  string msg;
  ob=this_player();
  if(!wizardp(ob))
  return 0;
  msg="这是一个巫师的地址簿，你可以使用以下命令：
  
  addcount      在地址簿中添加一个帐号。
  
  editcount     编辑地址簿中一个帐号。
  
  listcount     当没有参数时，显示所有地址，当有参数时，
                显示你想看的地址。
            
  discardcount  从地址簿中删除一个巫师的地址。
  
  此地址簿玩家不能使用，但是在巫师之间没有设定权限
  的限制，也就是说wizard 也可以删除 admin 的地址。
  请各位巫师自觉使用。
  
                          真冰河(Yanyan)@大唐双龙
  \n";
  ob->start_more(msg);
  return 1;
}