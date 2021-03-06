
#include <ansi.h>
#include <job_money.h>

inherit JOBNPC;

string _invocation(object who, int level);
int expeward, pot_reward;
int other_kee=0, other_sen=0;

string *dirs1 = ({
"/d/chengdu","/d/changan","/d/yangzhou","/d/luoyang","/d/xiangyang"
});

string *dirs2 = ({
"/d/suiye","/d/huashan","/d/emeishan","/d/hengshan"
});

string *dirs3 = ({
"/d/dabashan","/d/taishan","/d/taishan"  
});

string *names1 = ({
  WHT"陈"NOR,"chen",
  WHT"杜"NOR,"du",
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
  WHT"伏"NOR,"fu",
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
  YEL"威"NOR,"wei",
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
  WHT"晓伟"NOR,"xiaowei",
  WHT"文伏"NOR,"wenfu",
  WHT"雄昌"NOR,"xiongchang",
  WHT"易卫"NOR,"yiwei",
  WHT"建俊"NOR,"jianjun",
  WHT"济松"NOR,"jisong",
  WHT"业惠"NOR,"yehui",
  WHT"川石"NOR,"chuanshi",
  WHT"百贞"NOR,"baizhen",
  WHT"峰飞"NOR,"fengfei",
  WHT"粱慧"NOR,"lianghui",
  WHT"荣阳"NOR,"rongyang",
  WHT"昆威"NOR,"kunwei",
  WHT"宇宙"NOR,"yuzhou",
  WHT"发栋"NOR,"fadong",
  WHT"然平"NOR,"ranping",
  WHT"凌江"NOR,"lingjiang",
  WHT"仁冉"NOR,"renran",
  WHT"庄业"NOR,"zhuangye",
  WHT"陈杜"NOR,"chendu",
  WHT"李张"NOR,"lizhang",
  WHT"王何"NOR,"wanghe",
  WHT"欧周"NOR,"ouzhou",
  WHT"胡马"NOR,"huma",
  WHT"麦史"NOR,"maishi",
  WHT"廖林"NOR,"liaolin",
  WHT"白菜"NOR,"baicai",
  WHT"金朝"NOR,"jinchao",
  WHT"卢吴"NOR,"luwu",
  WHT"黄严"NOR,"huangyan",
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
	WHT"嘉神"NOR,"jiashen",
	WHT"山歧"NOR,"shanqi",
	WHT"龙堂"NOR,"longtang",
});

int killer_type=0;

void _leave();
void leave();

void setname1()
{
        int i,j,k;
	string name, *id;

	i=(random(sizeof(names1)/3))*2;
	j=(random(sizeof(names2)/3))*2;
	k=(random(sizeof(names3)/3))*2;

	name=names1[i]+names2[j]+names3[k];
	id=({names1[i+1]+" "+names2[j+1]+names3[k+1], names1[i+1]});

	set_name(name,id);

	set("race", "人类");
      set("gender", "男性");
	killer_type=1;
}

void setname2()
{
    int i, j;
    string name, *id;
    i=(random(sizeof(names4)/3))*2;
    j=random(2);
 name=names4[i]+(j?YEL"行者"NOR:YEL"隐士"NOR);
    id=({names4[i+1]+" "+(j?"xingzhe":"yinshi"),
	    (j?"xingzhe":"yinshi")});    

    set("race", "人类");
    set("gender","男性");
    set_name(name,id);
    killer_type=2;
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
	set_temp("apply/armor",5+random(5));
	
	
	
        setup();
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
        int exp;
        object me=this_object();
        
        exp=who->query("combat_exp");
	if(exp<150000){
         set_this_skills("low");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1,2); //copy 气血
         copy_hp_item(who,me,"gin",1,2); //copy 精血
         copy_hp_item(who,me,"sen",1,2); //copy 精神
        }
        else
        if(exp<500000){
         set_this_skills("middle");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1,2); //copy 气血
         copy_hp_item(who,me,"gin",1,2); //copy 精血
         copy_hp_item(who,me,"sen",1,2); //copy 精神
        }
        else
        if(exp<1000000){
         set_this_skills("high");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1,2); //copy 气血
         copy_hp_item(who,me,"gin",1,2); //copy 精血
         copy_hp_item(who,me,"sen",1,2); //copy 精神
         set("jiali",1);
        }
        else{
         set_this_skills("high");
         me->set("combat_exp",who->query("combat_exp")/3);
         set_all_skill(me,who->query("max_pot")/3); 
         copy_hp_item(who,me,"kee",1,2); //copy 气血
         copy_hp_item(who,me,"gin",1,2); //copy 精血
         copy_hp_item(who,me,"sen",1,2); //copy 精神
         set("jiali",2);
        }
               
        me->set("max_force",who->query("max_force")/3);//杀手内力随着做的次数增加
        me->set("force",who->query("max_force")/3);
        
        me->set("target_id",who->query("id"));//只允许做任务的人杀，其他人杀不了。
        me->set("pfm_rate",60+level*2);//杀手出perform的概率。
      me->delete("perform_quest");
	
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
        long="一位"+name()+"，被追杀了有"+
	  chinese_number((query("combat_exp")/1000/10)*10>60?60:
	  (query("combat_exp")/1000/10)*10)+
	  "年的人。他";
        if(random(2)==0) {
	  set("long",long+"通体透出一股杀气。\n");
        } else {
	  set("long",long+"混身上下杀气逼人。\n");
        }
	} else if(killer_type==2) {
	    int dx=query("combat_exp");
	    long="一位"+query("name")+
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
		        
	if(exp<1000000) {
	  
	    dirs=dirs1;
//+dirs2;
	} else if(exp<3000000) {
	    dirs=dirs+dirs2;
	} else {
	    dirs=dirs+dirs2+dirs3;
	}

	
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
	    exp=(who->query("combat_exp"))/3;
	    myexp=(query("combat_exp"))/3;
	    if(exp>myexp*3 || exp<myexp)
		break;
            if(query("owner")==this_player()->
		    query("id")){
	      set_leader(who);
	      message_vision("$N盯着$n，发出让人心寒的笑声：嘿嘿．．．\n",
		    this_object(), who);
	      kill_ob(who);
	    }
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
	   // add_action("do_block","",1);
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
       

        killer=query_temp("last_damage_from");//得到当前杀死他的人的物件。
        
        if(!killer) return ::die();
        
        if(killer->query("id")!=query("target_id"))//看是否是做任务的人
         return ::die();
        
        JOBSYS_D->give_reward_killerjob(killer);
                      
        killer->delete_temp("cisha/name");
        killer->delete_temp("cisha/ob");
        killer->delete_temp("dtsl_job");
        killer->set("busy_time",time());
        return ::die();
}

