
inherit NPC;
#include <ansi.h>
int do_jiehun(string arg);
int do_devorce(string arg);
void create()
{
   set_name(HIY"月老"NOR,({ "yue lao","yue","lao"}) );
        set("gender", "男性" );
        set("age", 62);
		
   set("long", "这就是神话中的为男女撮合婚姻的月老。\n");       
   set("combat_exp", 5000);
   set("str", 20);
   set("per", 25);
   set("attitude", "peaceful");
   setup();
  
}

void init()
{
   add_action("do_jiehun","jiehun");
   add_action("do_devorce","lihun");
   
}

int do_jiehun(string arg)
{
   object me,ob;string flag,id;
   object marry_token1,marry_token2;
   object liwu1,liwu2,liwu3,liwu4,liwu5,liwu6;
   me=this_player();
   
   if(!arg||
     sscanf(arg,"%s %s",flag,id)!=2||flag!="with")
    return notify_fail("月老笑道："+RANK_D->query_respect(me)+",不要着急，请用jiehun with 人\n");
   if(me->query("class")=="bonze")
   return notify_fail("月老笑笑：出家人四大皆空，我看你还是算了！\n");
   if(me->query("gender")=="女性")
   return notify_fail("这种事情女孩子家怎么能出头呢？让男方来吧！\n");
   if(me->query("couple"))
   return notify_fail("你已经结婚了，怎么，难道还要捉弄姻缘吗？\n");
   if(!objectp(ob=present(id,environment(me))))
   return notify_fail("月老四下看了看：咦？没有这个人啊？\n");
   if(ob->query("class")=="bonze")
   return notify_fail("月老笑道：她是出家人，怎么会答应你呢？我看你俩是有缘无份啊！\n");
   if(ob->query("couple"))
   return notify_fail("月老笑道：小心他的丈夫来打你！\n");
   if(me->query_temp("marry")!=ob)
   return notify_fail("月老奇道：你并没有向她求婚！\n");
   if(ob->query_temp("marry")!=me)
   return notify_fail("月老奇道：她并没有答应你的请求，这、这怎么可以？！\n");
   command("say 呵呵，看来俩位是姻缘注定，祝你们俩位白头偕老，早生贵子。\n");
   command("smile\n");
   message("vision",HIY"【大唐姻缘谱】："+me->name()+HIY+"与"+ob->name()+HIY+"结为夫妇。\n"NOR,users());
   message("vision",HIY"【大唐姻缘谱】：祝你们白头到老，永结同心！\n"NOR,users());
   message("vision",HIY"【大唐姻缘谱】：他们在月老亭举办酒席，欢迎各位豪侠去助兴！\n"NOR,users());
   marry_token1=new("/obj/yupei");
   marry_token1->move(ob);
   marry_token1->wear();
   marry_token2=new("/obj/xiangnang");
   marry_token2->move(me);
   marry_token2->wear();
   me->set("couple/couple_id",ob->query("id"));
   me->set("couple/couple_name",ob->name());
   ob->set("couple/couple_name",me->name());
   ob->set("couple/couple_id",me->query("id"));
   tell_object(me,"月老在你耳边悄声道：你可以使用makelove命令。\n");
   tell_object(ob,"月老在你耳边悄声道：你可以使用makelove命令。\n");
   tell_object(me,ob->name()+"满脸羞红地望着你。\n");
   tell_object(ob,me->name()+"满脸兴奋地望着你。\n");
   liwu1=new(__DIR__"obj/liwu1");
   liwu2=new(__DIR__"obj/liwu2");
   liwu3=new(__DIR__"obj/liwu3");
   liwu4=new(__DIR__"obj/liwu4");
   liwu5=new(__DIR__"obj/liwu5");
   liwu6=new(__DIR__"obj/liwu6");
   liwu1->move(environment(me));
   liwu2->move(environment(me));
   liwu3->move(environment(me));
   liwu4->move(environment(me));
   liwu5->move(environment(me));
   liwu6->move(environment(me));
   return 1;
}

int do_devorce(string arg)
{
   object me,ob;
   object token1,token2;
   string flag,id;
   me=this_player();
   if(!arg||sscanf(arg,"%s %s",flag,id)!=2||
      flag!="with")
   return notify_fail("月老低声道：请用 lihun with 人。\n");
   if(!me->query("couple"))
   return notify_fail("月老道：你还没有结婚，和谁结婚啊？\n");
   if(!objectp(ob=present(id,environment(me))))
   return notify_fail("月老四下看看，没有这个人啊？\n");
   if(me->query("couple/couple_id")!=ob->query("id"))
   return notify_fail("你们不是夫妇，如何离婚？\n");
   command("say 既然你们姻缘已完，我也没什么好说的。\n");
   command("say 愿你们以后好自为之！\n");
   if(me->query("gender")=="男性")
   token1=present("xiang nang",me);
   else token1=present("yu pei",me);
   if(token1) destruct(token1);
   if(ob->query("gender")=="男性")
   token2=present("xiang nang",ob);
   else token2=present("yu pei",ob);
   if(token2) destruct(token2);
   me->delete("couple");
   ob->delete("couple");
   command("chat "+me->name()+"与"+ob->name()+"姻缘已散，以后各自生活！\n");
   return 1;
}
   
    
