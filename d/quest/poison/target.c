//modified by vikee 2000.7.29


#include <ansi.h>
#include <job_money.h>

inherit NPC;
inherit __DIR__"killer_reward.c";

string _invocation(object who, int level);
int expeward, pot_reward;
int other_kee=0, other_sen=0;

string *dirs1 = ({
"/d/yangzhou",
});

string *dirs2 = ({
"/d/hangzhou",
});

string *dirs3 = ({
"/d/chanyuan",  
});

string *names1 = ({
  WHT"陈"NOR,"chen",
  WHT"八"NOR,"ba",
  WHT"李"NOR,"li",
  WHT"张"NOR,"zhang",
  WHT"王"NOR,"wang",
  WHT"何"NOR,"he",
  WHT"欧"NOR,"ou",
  WHT"周"NOR,"zhou",
  WHT"胡"NOR,"hu",
  WHT"马"NOR,"ma",
  WHT"麦"NOR,"mai",
  WHT"史"NOR,"shi",
  WHT"廖"NOR,"liao",
  WHT"林"NOR,"lin",
  WHT"白"NOR,"bai",
  WHT"菜"NOR,"cai",
  WHT"金"NOR,"jin",
  WHT"朝"NOR,"chao",
  WHT"卢"NOR,"lu",
  WHT"吴"NOR,"wu",
  WHT"黄"NOR,"huang",
  WHT"严"NOR,"yan",
});

string *names2 = ({
  WHT"晓"NOR,"xiao",
  WHT"伟"NOR,"wei",
  WHT"文"NOR,"wen",
  WHT"神"NOR,"shen",
  WHT"雄"NOR,"xiong",
  WHT"昌"NOR,"chang",
  WHT"易"NOR,"yi",
  WHT"卫"NOR,"wei",
  WHT"建"NOR,"jian",
  WHT"俊"NOR,"jun",
  WHT"济"NOR,"ji",
  WHT"松"NOR,"song",
  WHT"业"NOR,"ye",
  WHT"惠"NOR,"hui",
  WHT"川"NOR,"chuan",
  WHT"石"NOR,"shi",
  WHT"百"NOR,"bai",
  WHT"贞"NOR,"zhen",
});

string *names3 = ({
  YEL"峰"NOR,"feng",
  YEL"飞"NOR,"fei",
  YEL"粱"NOR,"liang",
  YEL"慧"NOR,"hui",
  YEL"荣"NOR,"rong",
  YEL"阳"NOR,"yang",
  YEL"昆"NOR,"kun",
  YEL"庵"NOR,"an",
  YEL"宇"NOR,"yu",
  YEL"宙"NOR,"zhou",
  YEL"发"NOR,"fa",
  YEL"栋"NOR,"dong",
  YEL"然"NOR,"ran",
  YEL"平"NOR,"ping",
  YEL"凌"NOR,"ling",
  YEL"江"NOR,"jiang",
  YEL"仁"NOR,"ren",
  YEL"冉"NOR,"ran",
  YEL"庄"NOR,"zhuang",
  YEL"业"NOR,"ye",
});

string *names4 = ({
	WHT"欧阳"NOR,"ouyang",
	WHT"上官"NOR,"shangguan",
	WHT"宇文"NOR,"yuwen",
	WHT"藤堂"NOR,"tengtang",
	WHT"井上"NOR,"jingshang",
	WHT"松岛"NOR,"songdao",
	WHT"端木"NOR,"duanmu",
	WHT"木川"NOR,"muchuan",
	WHT"樱木"NOR,"yingmu",
	WHT"流川"NOR,"liuchuan",
	WHT"元颜"NOR,"yuanyan",
	WHT"司徒"NOR,"situ",
	WHT"十文字"NOR,"shiwenzi",
	WHT"堂本"NOR,"tangben",
	WHT"矢吹"NOR,"shichui",
	WHT"草雏"NOR,"caochu",
	WHT"二本目"NOR,"erbenmu",
	WHT"吉川"NOR,"jichuan",
	WHT"尺目"NOR,"chimu",
	WHT"嘉神"NOR,"jiatian",
	WHT"山歧"NOR,"shanqi",
	WHT"龙堂"NOR,"longtang",
});

int killer_type=0;

int random_place(object me, string* dirs);
void _leave();
void leave();

void setname1()
{
        int i,j,k;
	string name, *id;

	i=(random(sizeof(names1)/2))*2;
	j=(random(sizeof(names2)/2))*2;
	k=(random(sizeof(names3)/2))*2;

	name=names1[i]+names2[j]+names3[k];
	id=({names1[i+1]+names2[j+1]+" "+
	    names3[k+1], names3[k+1]});

	set_name(name,id);

	set("race", "人类");
      set("gender", "男性");
	killer_type=1;
}

void setname2()
{
    int i, j;
    string name, *id;
    i=(random(sizeof(names4)/2))*2;
    j=random(2);
 name=names4[i]+(j?YEL"一"NOR:YEL"二"NOR);
    id=({names4[i+1]+" "+(j?"yi":"er"),
	    (j?"jing":"guai")});    
// name=names4[i]+(j?YEL"龙"NOR:YEL"真吾"NOR:YEL"京"NOR:YEL"苍月"NOR:YEL"小次郎"NOR:YEL"幸二"NOR:YEL"柴舟"NOR:YEL"光宪"NOR:YEL"雷"NOR:YEL"化及"NOR:YEL"无敌"NOR:YEL"光一"NOR:YEL"千邹"NOR:YEL"却达"NOR:YEL"仁"NOR:YEL"千鹤"NOR:YEL"炎"NOR:YEL"耀"NOR);
// id=({names4[i+1]+" "+(j?"long":"zhenwu":"jing":"cangyue":"xiaocilang":"xinger":"chaizhou":"guanxian":"lei":"huaji":"wudi":"guangyi":"qianzhou":"queda":"ren":"qianhe":"yan":"yao"),
//	    (j?"long":"zhenwu":"jing":"cangyue":"xiaocilang":"xinger":"chaizhou":"guanxian":"lei":"huaji":"wudi":"guangyi":"qianzhou":"queda":"ren":"qianhe":"yan":"yao")});

    set("race", "人类");
    set("gender","男性");
    set_name(name,id);
    killer_type=2;
}

int cast_chance(int level) 
{
    return 5+level/2;
}

void create()
{
        if(random(2)==0)
	    setname1();
	else
	    setname2();

	set("chat_chance", 5);
	set("chat_msg", ({
	     (: random_move :)
	}) );

	set("chat_chance_combat", 5);

	set("age", 20+random(80));
	set("combat_exp", 3000);
	set_skill("unarmed", 10);
	set_skill("dodge", 10);
	set_temp("apply/armor", 25);
	
        setup();
}



int random_place(object me, string *dirs)
{
        int  i, j, k;
        object  newob;
        mixed *file, exit;
                

        if( !sizeof(dirs) )  return 1;

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.c", -1 );
        
        if(!sizeof(file))
         return 1;
                                 
	for(k=0;k<30;k++) { // try 20 times
		
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
		       !(exit=newob->query("exits")) ||
		       sizeof(exit)<1)
		   continue;

               if(me->move(newob)) {
               
		   message_vision("$N走了过来。\n",me);
		   break;
	       }
	     }
	   }
	}

        return 1;
}

void _leave()
{
    object me=this_object();
    
    // if in fighting, then don't disappear.
    if(me->is_fighting() || me->is_busy())
	return;
    leave();
}

void leave()
{
      if(this_object()) { 
        if(environment())
          message("vision",HIB + name() + 
		  "身形一闪，踪迹不见。\n" NOR,environment());
        destruct(this_object());
      }
      return;
}

string invocation(object who, int level)
{
        object me=this_object();
        
        
        set_all_skill(me,level*4+who->query("max_pot")-100);  //设定全部技能
        copy_hp_item(who,me,"kee"); //copy 气血
        copy_hp_item(who,me,"gin"); //copy 精血
        copy_hp_item(who,me,"sen"); //copy 精神
        me->set("max_force",who->query("max_force")+level*500);//杀手内力随着做的次数增加
        me->set("force",who->query("max_force")+level*500);
        
        me->set("target_id",who->query("id"));//只允许做任务的人杀，其他人杀不了。
	
	return _invocation(who, level);
}

string _invocation(object who, int level)
{       
	
	object me=this_object(), env;
        string *dirs; 
        int exp, i, lvl;
	string where, long, killer_name;
	
	dirs=dirs1;
         
       
        set("owner", who->query("id"));
        set("owner_ob", who);

	if(killer_type==1) {
        long="一个"+name()+"，被追杀了有"+
	  chinese_number((query("combat_exp")/1000/10)*10)+
	  "多年的人。他";
        if(random(2)==0) {
	  set("long",long+"通体透出一股杀气。\n");
        } else {
	  set("long",long+"混身上下杀气逼人。\n");
        }
	} else if(killer_type==2) {
	    int dx=query("combat_exp");
	    long="一只"+query("name")[0..<3]+
		"，在"+({"深山中","密林中","野外",
			"草原上","野林中","高山中",
			"莽林中","莽原上","深谷中",
			})[random(9)]+
	        "躲藏了"+({"很长","一段","一段长"})[random(3)]+
		    "时间，今日终于被人发现。\n";
            set("long",long);
	    
	    if(dx>=10000000)
		long=HBYEL HIW" 魔 头 "NOR;
	    else if(dx>=1000000)
		long=HBRED HIW" 强 者 "NOR;
	    else if(dx>=100000)
		long=HBBLU HIW" 高 手 "NOR;
	    else if(dx>10000)
		long=HIR"武 士"NOR;
	    else
		long=HIY"流 氓"NOR;
	    
	    set("title",long);
	}

	lvl=level;
	
	// choose npc type.
	i=random(1000);
	if(i<10) {
	    set("type","aggressive");
	} else if(i<20) {
	    set("type","blocker");
	} else if(i<220) {
	    set("type","aggressive_on_owner");
	} else 
	    set("type","normal");
	
	if(random(10)==0) {
	    set("env/wimpy",40);
	    if(lvl<9) lvl=lvl+1; // as more difficult to kill.
	} else {
	    set("env/wimpy",1);
	}

	// determine reward
	
	exp=who->query("combat_exp");
	if(exp<30000) {
	    expeward=500+exp/60;
	    pot_reward=200+exp/300;
	} else if(exp<300000) {
	    expeward=1000+exp/600;
	    pot_reward=300+exp/6000;
	    dirs=dirs+dirs2;
	} else if(exp<3000000) {
	    expeward=1500+exp/6000;
	    pot_reward=350+exp/60000;
	    dirs=dirs+dirs2;
	} else {
	    expeward=2000;
	    pot_reward=400;
	    dirs=dirs+dirs2+dirs3;
	}

	pot_reward=pot_reward*(lvl+1)/10;
	expeward=expeward*(lvl+1)/10;

	me->set("stay_time", time()+1800);
		
	if(!random_place(me, dirs)) {
	    leave();
	    return 0;
	}
	
	env=environment(me);
	killer_name=me->query("name")+"("+me->query("id")+")";
	where=killer_name;
	if(env)
	    where +="在"+MISC_D->find_place(env);
	return where;
}

int accept_object (object who, object ob)
{
  object me;
  me = this_object();

  if ((! ob) ||
       ob->value() < 100000)
  {
    message_vision ("$N一瞪眼：就这点东西？不想活了？？？\n", me);
    return 1;
  }
  who->set_temp("cisha/allow_to_go", 1);
  message_vision ("$N嘿嘿嘿几声怪笑：算你走运，快滚！"
	  +"可别让我再看见你！\n",me);
  return 1;
}

void check_room()
{
    object me=this_object();
    object env=environment(me);
    
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
               env->query("sleep_room")||
		env->query("no_exert"))) {
	random_move();
    }
}

void init()
{
    object me=this_object();
    object who=this_player();
    string type;
    int t=query("stay_time");

    ::init();
    
    if(t && time()>t) {
	remove_call_out("_leave");
	call_out("_leave",300);
    }
    
    if(!userp(this_player())) return;
    if(!living(this_object())) return;
    
    type=query("type");
    switch (type) {
	case "aggressive": {
	    object leader=query_leader();
	    int exp, myexp;
	    if(leader && present(leader, environment(me))) {
		if(!is_fighting()) kill_ob(leader);
		break;
	    }
	    exp=(who->query("combat_exp"))/2;
	    myexp=(query("combat_exp"))/2;
	    if(exp>myexp*3 || exp<myexp)
		break;

	    set_leader(who);
	    message_vision("$N盯着$n，发出让人心寒的笑声：嘿嘿．．．\n",
		    this_object(), who);
	    kill_ob(who);
	    break;
	}
	case "aggressive_on_owner":
	    if(query("owner")==this_player()->
		    query("id")) {
		message_vision("$N看见$n，大叫一声：终于被人发现了，我要杀人灭口！！\n",
			this_object(), who);
		kill_ob(this_player());
		this_player()->kill_ob(this_object());
	    }
	    break;
	case "blocker": {
	    add_action("do_block","",1);
	    break;
	}
    }
    remove_call_out("check_room");
    call_out("check_room",2);
}

int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    if(wizardp(who) && !visible(who)) return 0;
    if(me->is_fighting()) return 0;

    if(verb!="go" &&
	    !(environment() && environment()->query("exits/" + verb)))
	return 0;

    if(who->query_temp("cisha/allow_to_go")) {
	who->delete_temp("cisha/allow_to_go");
	who->delete_temp("cisha/leave_time");
	return 0;
    }
    t=who->query_temp("cisha/leave_time");
    if(t>0 && time()>t) {
	who->delete_temp("cisha/leave_time");
	message_vision("$n乘$N一个不注意，急忙溜了过去。\n",me,who);
	return 0;
    }
    if(t==0) {
        t=time()+30+random(90);
        who->set_temp("cisha/leave_time",t);
	message_vision("$N猛地跳过来拦在$n面前，高声叫道：\n"+
		"          此山是我开，此树是我栽！\n"+
		"          要打此路过，留下买路财！\n\n",me,who);
    } 
    
    tell_object(who,me->name()+"一把抓住了你！\n");
    return 1;
}


void die()
{
        object killer;
        string skill;
        object me=this_object();
	string str,msg;
	int exp,pot,lev;

        killer=query_temp("last_damage_from");//得到当前杀死他的人的物件。
        
        if(!killer) return ::die();
        
        if(killer->query("id")!=query("target_id"))//看是否是做任务的人
         return ::die();

           
             message_vision("$N「啪」的一声倒在地上，挣扎着抽动了几下就死了。\n",this_object());
	       
		    lev=killer->query_temp("cisha_job/level");
		    
		    exp=170+lev*5;
		    pot=100+lev*3;
		    
		    killer->add("combat_exp",exp);
		    killer->add("potential",pot);
		    
		   
		    killer->add_temp("cisha_job/level",1);//累计增加一次任务次数。
       if (killer->query_temp("cisha_job/level")==10) {
          skill=give_reward(killer);
          killer->delete_temp("cisha_job/level");
     	if (skill != "none"){
    message("shout",HIY"〖"HIW"买凶杀人"HIY"〗"HIY"杨虚延(yang xuyan):" HIR+ killer->query("name")+HIM"助我刺杀要人有功，故传授"HIY+ to_chinese(skill)+HIM"一级！\n"NOR,users()); 
// CHANNEL_D->do_channel(me,"rumor",msg);
    }



   }

		
		   tell_object(killer, HIY"你得到了"HIR+chinese_number(exp)
			    +"点"HIY"经验和"HIR+chinese_number(pot)+
			    "点"HIY"潜能！\n"NOR);

        killer->delete_temp("cisha/name");
        killer->delete_temp("cisha/ob");
        killer->delete_temp("dtsl_job");
      
	destruct(this_object());

}

