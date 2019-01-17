
inherit NPC;

void create()
{
   set_name("店小二",({ "dian xiaoer","xiaoer","dian"}) );
   set("gender", "男性" );
   set("age", 22);
		
   set("long", "这是有间客栈的店小二。\n");
       
   set("combat_exp", 30000);   
   set_skill("unarmed",50);
   set_skill("dodge",50);
   set_skill("parry",50);
 
   setup();
 
}

void init()
{
if(!living(this_object()))
	return;
remove_call_out("welcome");
call_out("welcome",1);
}

void welcome()
{

switch(random(3)){
	case 0:	
		command("say 最近我生生死死看的多了，客官您也看开一点吧！");
		break;
	case 1:
		command("say 各位爷请闪一闪，我要扫地了。");
		break;
	case 2:
		command("say 拼死争得天下又有什么用？我看不如早点娶个媳妇好！");
		break;
}
	
}
	

