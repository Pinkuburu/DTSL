//dt 
//
#include <ansi.h>

string query_rank(object ob)
{
 string *sword,*blade;int age,exp,mks,pks,deadtimes,i;
	age=(int)ob->query("age",1);
	exp=(int)ob->query("combat_exp",1);
	mks=(int)ob->query("MKS",1);
	pks=(int)ob->query("PKS",1);
	deadtimes=(int)ob->query("deadtimes",1);
	sword=ob->query("sword");blade=ob->query("blade");
	if(ob->query("env/class")) return HIG"【"+ob->query("env/class")+HIG"】"NOR;
	if(ob->query_temp("rank/class")) return HIG"【"+ob->query_temp("rank/class")+HIG"】"NOR;
	if(ob->is_ghost())
		return HIB "【 鬼  魂 】" NOR;
	switch(ob->query("gender"))
	{
	case "男性":
		{
			switch(wizhood(ob))
			{
			case "(admin)": return HIG"【 天  帝 】"NOR;
                        case "(arch)" : return HIR"【 大  神 】"NOR;
                        case "(wizard)" : return HIW"【 神  仙 】"NOR;
                        case "(apprentice)" : return HIY"【 仙  人 】"NOR;
			case "(immortal)": return HIG"【 半  仙 】"NOR;
			default:
				{
					if(ob->query("vocation")=="铁匠"&&ob->query("vocation_score")>=1000000)
						   return HIG"【兵器大师】"NOR;
					else if(ob->query("vocation")=="药师"&&ob->query("vocation_score")>=1000000)
							return HIY"【药王再世】"NOR;
					else if(ob->query("vocation")=="杀手"&&ob->query("vocation_score")>=1000000)
							return HIR"【杀手之王】"NOR;
                                        else  if(ob->query("vocation")=="商人"&&ob->query("vocation_score")>=1000000)
                                        return HIY"【财    神】"NOR;
                                        else if(ob->query("xiaqi/weiqi")>=900) return HIY"【围棋大师】"NOR;
                                        else if(ob->query("xiaqi/wuziqi")>=900) return HIY"【五子大师】"NOR;
					else if(sizeof(sword)>=10&&sizeof(blade)>=10) return HIG"【刀剑双绝】"NOR;
					else if(sizeof(sword)>=10) return HIG"【 剑  痴 】"NOR;
					else if(sizeof(blade)>=10) return HIG"【 刀  痴 】"NOR;
					else if(age<20&&exp>2000000) return HIG"【武林奇迹】"NOR;
					else if(age<20&&exp>1000000) return HIG"【江湖奇侠】"NOR;
					else if((mks+pks)>=1000000) return HIG"【杀人狂魔】"NOR;
					else if(deadtimes>=100) return HIR"【死亡战士】"NOR;
                                        else if(ob->query("family/family_name")=="净念禅院"){
                                               if(ob->query("family/generation")==8)
                                               return HIC"【俗家弟子】"NOR;
                                               if(ob->query("family/generation")==7)
                                               return HIC"【净念僧人】"NOR;
                                               if(ob->query("family/generation")==6)
                                               return HIY"【净念罗汉】"NOR;
                                               if(ob->query("family/generation")==5)
                                               return HIY"【净念尊者】"NOR;
                                               if(ob->query("family/generation")==4)
                                               return HIY"【净念大师】"NOR;
                                               if(ob->query("family/generation")==3)
                                               return HIY"【一代禅师】"NOR;
                                              }					
					else 
					 switch(ob->query("class"))
					{
			                  case "shibing": return HIG"【 士  兵 】"NOR;
					  case "xiaowei": return HIG"【 校  尉 】"NOR;
					  case "canjiang": return HIG"【 参  将 】"NOR;
					  case "guanchai": return HIG"【 官  差 】"NOR;
					  case "wujiang": return HIG"【 武  将 】"NOR;
					  case "jiangjun": return HIG"【 将  军 】"NOR;
			                  case "fighter": return HIG"【 战  士 】"NOR;//can add more
			               //yin gui rank
					  case "yin1": return HIY"【 人  黄 】"NOR;
					  case "yin2": return HIG"【 地  黑 】"NOR;
					  case "yin3": return HIW"【 天  白 】"NOR;
					  case "bonze": return HIG"【 和  尚 】"NOR;
				      //songjia-bao rank
				          case "song1": return HIG"【宋家门徒】"NOR;
				          case "song2": return HIG"【宋家少侠】"NOR;
				          case "song3": return HIG"【岭南刀侠】"NOR;
				     //dongming rank
				          case "dongming1": return HIG"【东溟少侠】"NOR;
				          case "dongming2": return HIG"【东溟战将】"NOR;
				          case "dongming3": return HIG"【东溟护法】"NOR;
				    //huajian rank.
				          case "hua1": return HIW"【风雅少侠】"NOR;
				          case "hua2": return HIW"【花间护法】"NOR;
				   //yi jian pai rank
				          case "yijian1": return HIG"【弈剑弟子】"NOR;
				          case "yijian2": return HIG"【弈剑剑师】"NOR;
				          case "yijian3": return HIY"【弈剑大师】"NOR;
				          case "gaoli1": return HIG"【高丽武士】"NOR;
				          case "gaoli2": return HIG"【宫廷卫士】"NOR;
				  //tujue rank
				          case "tujue1": return HIY"【突厥勇者】"NOR;
				          case "tujue2": return HIY"【突厥武士】"NOR;
				          case "tujue3": return HIY"【突厥护帅】"NOR;
				  	default:
						  
						  {   i=ob->query("age");
							  if(i<=18) return "【 少  年 】";
							  if(i<=30) return "【青年男子】";
							  if(i<=40) return "【中年男子】";
							  if(i<=60) return "【老年男子】";
							  if(i<=100) return "【花甲老人】";
							  if(i>100) return "【泥潭寿星】";
						  }
					}
				}
			}
		}

    case "女性":
		{
			switch(wizhood(ob))
			{
			case "(admin)": return HIG"【 天  仙 】"NOR;
                        case "(arch)" : return HIR"【 龙  女 】"NOR;
                        case "(wizard)" : return HIW"【 巫  女 】"NOR;
                        case "(apprentice)" : return HIY"【 巡  使 】"NOR;
			case "(immortal)": return HIG"【 半  仙 】"NOR;
			default:
				{
					if(ob->query("vocation")=="铁匠"&&ob->query("vocation_score")>=1000000)
						   return HIG"【兵器大师】"NOR;
					else if(ob->query("vocation")=="药师"&&ob->query("vocation_score")>=1000000)
							return HIY"【药王再世】"NOR;
					else if(ob->query("vocation")=="杀手"&&ob->query("vocation_score")>=1000000)
							return HIR"【杀手之王】"NOR;
                                        else  if(ob->query("vocation")=="商人"&&ob->query("vocation_score")>=1000000)
                                        return HIY"【财    神】"NOR;
                                        else if(ob->query("xiaqi/weiqi")>=900) return HIY"【围棋大师】"NOR;
                                        else if(ob->query("xiaqi/wuziqi")>=900) return HIY"【五子大师】"NOR;
					else if(sizeof(sword)>=10&&sizeof(blade)>=10) return HIG"【刀剑双绝】"NOR;
					else if(sizeof(sword)>=10) return HIG"【 剑  痴 】"NOR;
					else if(sizeof(blade)>=10) return HIG"【 刀  痴 】"NOR;
					else if(age<20&&exp>2000000) return HIG"【武林奇迹】"NOR;
					else if(age<20&&exp>1000000) return HIG"【江湖奇侠】"NOR;
					else if((mks+pks)>=1000000) return HIG"【杀人魔女】"NOR;
					else if(ob->query_skill("wuwang-jing",1)>400) return HIY"【一代神尼】"NOR;
					else if(deadtimes>=100) return HIG"【死亡战士】"NOR;
					else if(ob->query("family/family_name")=="慈航静斋"&&
					        ob->query("class")=="bonze") return HIY"【静斋神尼】"NOR;
					else if(ob->query("execute_quest/xinyoulingxi"))
					     return HIG"【心有灵犀】"NOR;
					else if(ob->query("execute_quest/jianxintongming"))
					     return HIG"【剑心通明】"NOR;
					else
					switch(ob->query("class"))
					{
			                  case "shibing": return HIG"【 士  兵 】"NOR;
					  case "xiaowei": return HIG"【 校  尉 】"NOR;
					  case "canjiang": return HIG"【 参  将 】"NOR;
					  case "guanchai": return HIG"【 官  差 】"NOR;
					  case "wujiang": return HIG"【 武  将 】"NOR;
					  case "jiangjun": return HIG"【 将  军 】"NOR;
			                  case "fighter": return HIG"【 战  士 】"NOR;//can add more
			                  case "bonze": return HIG"【 尼  姑 】"NOR;
					  //yingui rank                                          
			                  case "yin_guan": return HIR"【阴癸仙子】"NOR;
			                  case "yin1": return HIY"【 人  黄 】"NOR;
                                          case "yin2": return HIG"【 地  黑 】"NOR;
					  case "yin3": return HIW"【 天  白 】"NOR;
					  //lingnan rank
					  case "song1": return HIG"【宋家门徒】"NOR;
				          case "song2": return HIG"【宋家少侠】"NOR;
				          case "song3": return HIG"【岭南刀侠】"NOR;
				          //dongming rank
				          case "dongming1": return HIG"【东溟女侠】"NOR;
				          case "dongming2": return HIG"【东溟仙子】"NOR;
				          case "dongming3": return HIG"【东溟护法】"NOR;
				          //jingzhai rank.
				          case "jingzhai1": return HIW"【慈航仙子】"NOR;
				          case "jingzhai2": return HIW"【慈航仙子】"NOR;
				          //huajian rank.
				          case "hua1": return HIW"【风雅女侠】"NOR;
				          case "hua2": return HIW"【花间护法】"NOR;
				          //yi jian pai rank
				          case "yijian1": return HIG"【弈剑弟子】"NOR;
				          case "yijian2": return HIG"【弈剑剑师】"NOR;
				          case "yijian3": return HIY"【弈剑大师】"NOR;
				          case "gaoli1": return HIG"【高丽武士】"NOR;
				          case "gaoli2": return HIG"【宫廷卫士】"NOR;
				          //tujue rank
				          case "tujue1": return HIY"【塞外女侠】"NOR;
				          case "tujue2": return HIY"【突厥女官】"NOR;
				          case "tujue3": return HIY"【突厥护帅】"NOR;
				          
				          case "bonze":  return HIY"【尼    姑】"NOR;
					  default:
						 
						  {   i=ob->query("age");
							  if(i<=18) return "【 少  女 】";
							  if(i<=30) return "【妙龄女子】";
							  if(i<=40) return "【中年女子】";
							  if(i<=60) return "【老年女子】";
							  if(i<=100) return "【花甲老人】";
							  if(i>100) return "【泥潭寿星】";
						  }
					}
				}
			}
		}
	}
} 


string query_respect(object ob)
{
	int age;
       if(ob->query("race")!="人类")
			return "野兽";
   age=ob->query("age");
   if(ob->query("rank_respect"))
    return ob->query("rank_respect");
	switch(ob->query("gender"))
	{
	case "男性":
		{
			if((string)ob->query("class")=="bonze")
			{
				if(age<18) return "小和尚";
				else if(age<30) return "僧人";
				else if(age<40) return "大师";
				else return "高僧";
			}
			else
			{
				if(age<18) return "小兄弟";
				else if(age<30) return "壮士";
				else if(age<60) return "兄台";
				else return "老先生";
			}
		}
	case "女性":
		{
			if((string)ob->query("class")=="bonze")
			{
				if(age<18) return "小师太";
				else if(age<30) return "师太";
                else return "老师太";
			}
			else
			{
				if(age<18) return "小姑娘";
				else if(age<40) return "姑娘";
				else if(age<60) return "夫人";
				else return "婆婆";
			}
		}
	}
}

string query_rude(object ob)
{
	int age;string race;
	race=(string)ob->query("race");
	if(ob->query("race")!="人类")
			return "野兽";
	if(ob->query("rank_rude"))
    return ob->query("rank_rude");
	age=ob->query("age");
 switch(race)
 {
  case "飞禽": 
  case "野兽": return "小畜生";
  default:
   {  
	switch(ob->query("gender"))
	{
	 case "男性":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "小秃驴";
				 else if(age<30) return "秃驴";
				 else return "老秃驴";
			 }
			 else
			 {
				 if(age<18) return "小王八蛋";
				 else if(age<30) return "老混蛋";
				 else return "老匹夫";
			 }
		 }
	 case "女性":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "贱尼姑";
				 else if(age<30) return "死尼姑";
				 else return "老尼姑";
			 }
			 else
			 {
				 if(age<18) return "小贱人";
				 else if(age<30) return "贱人";
				 else return "死老婆子";
			 }
		 }
	}
   }

 }
}

string query_self(object ob)
{
   int age;string str;
   age=ob->query("age");
   if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;
   switch(ob->query("gender"))
   {
     case "男性":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "小僧";
				 else if(age<60) return "贫僧";
				 else return "老僧";
			 }
			 else
			 {
				 if(age<18) return "小生";
				 else if(age<60) return "在下";
				 else return "老头子";
			 }
		 }
	 case "女性":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "小尼";
				 else if(age<60) return "贫尼";
				 else return "老尼";
			 }
			 else
			 {
				 if(age<18) return "小女子";
				 else if(age<60) return "妾身";
				 else return "老婆子";
			 }
		 }

   }
}
		 
  
string query_self_rude(object ob)
{
   int age;string str;
   age=ob->query("age");
   
        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;
   switch(ob->query("gender"))
   {
     case "男性":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "小和尚";
				 else if(age<30) return "和尚我";
				 else return "老和尚我";
			 }
			 else
			 {
				 if(age<18) return "小爷我";
				 else if(age<30) return "相公我";
				 else return "你爷爷我";
			 }
		 }
	 case "女性":
		 {
			 if((string)ob->query("class")=="bonze")
			 {
				 if(age<18) return "小尼姑我";
				 else if(age<30) return "尼姑我";
				 else return "老尼姑我";
			 }
			 else
			 {
				 if(age<18) return "本小姐";
				 else if(age<30) return "本姑娘";
				 else return "老娘我";
			 }
		 }

   }
}
		 	

string query_close(object ob, int age, string rgender)
{
	int a1, a2;
	string gender;
	if (objectp(ob) )       {
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}
	
	if( !rgender )
		gender = ob->query("gender");					   
	else    gender = rgender;

	switch ( gender ) {
	case "女性" :
		if (a1 > a2)
			return "妹妹";
		else
			return "姐姐";
		break;
	default :
		if (a1 > a2)
			return "弟弟";
		else
			return "哥哥";
	}
}

string query_self_close(object ob, int age)
{
	int a1, a2;
	string gender;
	
	if(!ob)
	return "";
	
	if( objectp(ob) ) {
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}

	if( age )
		gender = ob->query("gender");
	else
		gender = this_player()->query("gender");

	switch (gender) {

	case "女性" :
		if (a1 > a2)
			return "姐姐我";
		else
			return "小妹我";
		break;
	default :
		if (a1 > a2)
			return "愚兄我";
		else
			return "小弟我";
	}
}


