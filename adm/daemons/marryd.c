//marryd.c for dt.
//written by yanyan.

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_DBASE;
#include <badid.h>

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
   "真冰河", "仲少", "寇仲", "徐子陵", "它妈的","江泽民","邓小平","一世情缘",
});



object make_body(object ob);
int check_legal_id(string id);
int check_legal_name(string name);
private void yes_no(string arg, object me,object user,object ob);
private void choose_gift(string arg, object me,object user,object ob);

void create() 
{
   seteuid(getuid());
   set("channel_id", "生育精灵");
   set("id", "marryd");
}
void do_birth(object me)
{
  object ob;
  
  tell_object(me,HIY"\n\n恭喜你，要生孩子了！请为你的孩子选个id吧：\n\n"+NOR);
  ob=new("/obj/login");
  input_to("get_id",1,me,ob);
  return ;
}
void get_id(string id,object me,object ob)
{
  if(file_size("/data/login/"+id[0..0]+"/"+id+".o")>0){
    	tell_object(me,"这个名字已经有了，换一个吧！\n\n");
    	input_to("get_id",1,me,ob);
    	return;}
    if(!check_legal_id(id)){
    	input_to("get_id",1,me,ob);
    	return;}
    ob->set("id",id);
    tell_object(me,"为你的孩子取一个中文名字吧：\n");
    input_to("get_name",1,me,ob);
}

void get_name(string name,object me,object ob)
{
  if(!check_legal_name(name)){
    input_to("get_name",1,me,ob);
    return;}
  ob->set("name",name);
  tell_object(me,"\n请选择你孩子的性别：男性(Male) 女性(Female)\n");
  input_to("get_gender",1,me,ob);
}
void get_gender(string arg,object me,object ob)
{
  if(arg==""){
  tell_object(me,"你只能选择男性或女性:男性(Male) 女性(Female)\n");
  input_to("get_gender",1,me,ob);return;}
  if(arg[0]=='f'||arg[0]=='F'){
  	ob->set("gender","女性");}
  else if(arg[0]=='M'||arg[0]=='m')
    ob->set("gender","男性");
  else { 
  	tell_object(me,"你只能选择男性或女性：男性(Male) 女性(Female)\n");
  	input_to("get_gender",1,me,ob);
  	return;
  }
 tell_object(me,"\n请设定您的孩子的密码：");
 input_to("get_passwd",1,me,ob);
}
void get_passwd(string pass,object me,object ob)
{
  if(sizeof(pass)<5){
  	tell_object(me,"\n密码长度至少五位：");
  	input_to("get_passwd",1,me,ob);
  	return;
  }
  ob->set("password", crypt(pass,0) );
  tell_object(me,"\n请再输入一次密码:");
  input_to("confirm_pass",1,me,ob);
}

void confirm_pass(string pass,object me,object ob)
{
  string oldpass;object user;string id,oldid;
  oldpass=ob->query("password");
  if( crypt(pass, oldpass)!=oldpass ){
  	tell_object(me,"\n两次输入的密码不一致，请重新输入：");
  	input_to("get_passwd",1,me,ob);
  	return;
  }
  ob->set("body", USER_OB);
  if(!objectp(user=make_body(ob))){
  	tell_object(me,HIR"无法继续下去，请使用SOS命令报告巫师！\n"NOR);
  	return;
  }
  
  tell_object(me,"\n请选择你的孩子的类型：\n");
  tell_object(me,"\n(a)"HIR"〖勇猛型〗"NOR"：膂力：24  根骨：12  悟性：12  身法：12\n");
  tell_object(me,"(b)"HIY"〖根骨型〗"NOR"：膂力：12  根骨：24  悟性：12  身法：12\n");
  tell_object(me,"(c)"WHT"〖智慧型〗"NOR"：膂力：12  根骨：12  悟性：24  身法：12\n");
  tell_object(me,"(d)"HIC"〖敏捷型〗"NOR"：膂力：12  根骨：12  悟性：12  身法：24\n");
  tell_object(me,"(e)"HIG"〖平均型〗"NOR"：膂力：15  根骨：15  悟性：15  身法：15\n");
  tell_object(me,"\n类型的选择和今后生活有很大关系，如果不清楚，建议先\n"+
	 "到相关站点去查询。\n"+
	 "请选择吧：\n");
  input_to((:choose_gift:), me,user,ob);
  return;
}

private void choose_gift(string arg, object me,object user,object ob)
{
	if(arg!="a"&&arg!="b"&&arg!="c"&&arg!="d"&&arg!="e"){
	  tell_object(me,"\n你只能选择\n (a)"HIR"〖勇猛型〗"NOR"(b)"HIY"〖根骨型〗"NOR"(c)"WHT"〖智慧型〗"NOR"(d)"HIC"〖敏捷型〗"NOR"(e)"HIG"〖平均型〗"NOR"\n 中的一种。\n");
	  tell_object(me,"你想选择哪一种类型：\n");
	  input_to((:choose_gift:), me,user,ob);
	  return;
	}
	if(arg=="a"){
	  user->set("str",24);
	  user->set("con",12);
	  user->set("int",12);
	  user->set("dex",12);
	  user->set("char_lev/char_type","str");
	}
	else
	if(arg=="b"){
	  user->set("str",12);
	  user->set("con",24);
	  user->set("int",12);
	  user->set("dex",12);
	  user->set("char_lev/char_type","con");
	}
	else
	if(arg=="c"){
	  user->set("str",12);
	  user->set("con",12);
	  user->set("int",24);
	  user->set("dex",12);
	  user->set("char_lev/char_type","int");
	}
	else
	if(arg=="d"){
	  user->set("str",12);
	  user->set("con",12);
	  user->set("int",12);
	  user->set("dex",24);
	  user->set("char_lev/char_type","dex");
	}
	else{
	  user->set("str",15);
	  user->set("con",15);
	  user->set("int",15);
	  user->set("dex",15);
	  user->set("char_lev/char_type","middle");
	}
	printf("\n你确定吗？(Yes/No)\n");
	input_to((:yes_no:), me,user,ob);
	return;
}

private void yes_no(string arg, object me,object user,object ob)
{
	int food,water;
	
	if(arg=="Yes"||arg=="yes"||arg=="Y"||arg=="y")
	  tell_object(me,"\n属性选择完毕！\n");
	else
	if(arg=="No"||arg=="no"||arg=="N"||arg=="n"){
	  tell_object(me,"\n好吧，请重新选择：\n");
	  tell_object(me,"\n(a)"HIR+"〖勇猛型〗"NOR"(b)"HIY"〖根骨型〗"NOR"(c)"WHT"〖智慧型〗"NOR"(d)"HIC"〖敏捷型〗"NOR"(e)"HIG"〖平均型〗"NOR"\n");
	  input_to((:choose_gift:), me,user,ob);
	  return;
	}
	else{
	  printf("\n你确定吗？(Yes/No)\n");
	  input_to((:yes_no:), me,user,ob);
	  return;
	}
  tell_object(me,HIY"\n你的孩子先天获得 30 点属性，可以自由分配。\n"NOR); 
  user->add("char_lev/points",30);
  
  user->set("birthday", time() );
  user->set("food", 1000);
  user->set("water", 1000);
  user->set("channels", ({ "chat","rumor","dt","banghui","party","sale"}));
  user->set_temp("link_ob", ob);
  user->set_encoding(me->query_encoding());
  user->set("password",ob->query("password"));
  user->set("body",ob->query("body"));
  user->set("gender",ob->query("gender"));
  user->set("title","普通百姓");
  user->set("startroom","/d/newbie/door");
  user->set("pass_test",1);
  user->set("per",10+random(11)+random(11));
  user->set("kar",10+random(11)+random(11));
  user->set_temp("link_ob", ob);
  ob->set_temp("body_ob", user);
  user->setup();
  
  message("vision",HIY"【大唐风云】：据说有一个叫"+HIG+user->query("name")+HIY+"的"+
          "新英雄诞生了！\n"NOR,users());
  
  user->save();
  ob->save();
  destruct(ob);
  destruct(user);
  tell_object(me,"\n\n你的孩子已经出生了，你可以使用孩子的账号进行登录。\n");
  return;
}

object make_body(object ob)
{
   string err;
   object user;
   int n;

        if(!ob->query("body")) {
     return 0;
        }
   user = new(ob->query("body"));
   if(!user) {
     write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
     write(err+"\n");
     return 0;
   }
   seteuid(ob->query("id"));
   export_uid(user);
   export_uid(ob);
   seteuid(getuid());
   user->set("id", ob->query("id"));
   user->set_name( ob->query("name"), ({ ob->query("id")}) );
   return user;
}

int check_legal_id(string id)
{
   int i;
   string *legalid;

   i = strlen(id);
   
   if( (strlen(id) < 3) || (strlen(id) > 8 ) ) {
     write("对不起，你的英文名字必须是 3 到 8 个英文字母。\n");
     return 0;
   }
   while(i--)
     if( id[i]<'a' || id[i]>'z' ) {
        write("对不起，你的英文名字只能用英文字母。\n");
        return 0;
     }


 if(member_array(id,badid)!=-1){
	write("对不起，请不要使用这种英文名字。\n");
        return 0;}
   return 1;
}

int check_legal_name(string name)
{
   int i;

   i = strlen(name);
   
   if( (strlen(name) < 2) || (strlen(name) > 8 ) ) {
     write("对不起，你的中文名字必须是 1 到 4 个中文字。\n");
     return 0;
   }
   while(i--) {
     if( name[i]<=' ' ) {
        write("对不起，你的中文名字不能用控制字元。\n");
        return 0;
     }
     if( i%2==0 && !is_chinese(name[i..<0]) ) {
        write("对不起，请您用「中文」取名字。\n");
        return 0;
     }
   }
   if( member_array(name, banned_name)!=-1 ) {
     write("对不起，这种名字会造成其他人的困扰。\n");
     return 0;
   }

   return 1;
}