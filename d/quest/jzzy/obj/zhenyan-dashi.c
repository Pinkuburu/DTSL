
inherit NPC;
string do_quest1();
string do_quest2();
string do_quest3();
string do_quest4();
void create()
{
       set_name("真言大师", ({ "zhenyan dashi"}) );
       set("gender", "男性" );
       set("age",60);
       set("long","这是一位佝楼背脊的灰袍老僧。\n");
       set("combat_exp",20000000);
       set("inquiry",([
          "打扫":(:do_quest1:),
          "坐禅":(:do_quest2:),
          "禅定":(:do_quest3:),
          "九字真言":(:do_quest4:),
          ]));
       setup();
 
}

string do_quest1()
{
  object ob;
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_jzzy/step10"))
   return "你说的什么？老僧可是一点也不懂啊！\n";
  ob->set_temp("dtsl_quest_jzzy/step11",1);
   ob->delete_temp("dtsl_quest_jzzy/step10");
  return "施主有这心意就成！打扫佛堂，乃老衲的职责，怎可假他人之手。\n";
}
string do_quest2()
{
  object ob;
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_jzzy/step11"))
   return "你说的什么？老僧可是一点也不懂啊！\n";
  if(ob->query_int()<50)
  return "看施主还是犹如顽石，尚无慧根，问这些又有什么用呢？\n";
  ob->set_temp("dtsl_quest_jzzy/step12",1);
   ob->delete_temp("dtsl_quest_jzzy/step11");
  return "一念不起为坐，见本性不乱为禅。\n";
}

string do_quest3()
{
  object ob;
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_jzzy/step12"))
   return "你说的什么？老僧可是一点也不懂啊！\n";
  if(ob->query_int()<50)
  return "看施主还是犹如顽石，尚无慧根，问这些又有什么用呢？\n";
  ob->set_temp("dtsl_quest_jzzy/step13",1);
   ob->delete_temp("dtsl_quest_jzzy/step12");
  return "外不著相为禅，内不乱为定。外禅内定，故名禅定，即时豁然，还得本心。\n";
}

string do_quest4()
{
  object ob;
  ob=this_player();
  
  if(!ob->query_temp("dtsl_quest_jzzy/step13"))
   return "你说的什么？老僧可是一点也不懂啊！\n";
  ob->delete_temp("dtsl_quest_jzzy");
  ob->set("dtsl_quest_jzzy_ok",1);
  return "像施主这么坦白真诚，全无贪慎痴念的人，纵在空门之中\n"+
         "亦属罕有。百多年来，老衲曾先后游历中外名寺古刹五千六百五十二所，\n"+
         "最后把所有印结归纳在“九字真言手印”内，今见施主有缘，竟有不吐不\n"+
         "快的俗念尘心，确为异数。不动根本印，大金刚轮印，外狮子印、内狮子\n"+
         "印、外缚印、内缚印、智拳印、日轮印和宝瓶印。\n";
}
