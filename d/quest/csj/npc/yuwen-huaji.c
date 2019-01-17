
inherit NPC;
#include <ansi.h>

void create()
{
   object *ob;
   set_name("宇文化及",({ "yuwen huaji","yuwen"}) );
   set("gender", "男性" );
   set("no_get", 1 );
   set("age", 32);
   set("long","他是宇文阀的高手之一，据说正在寻找长生诀。\n");
   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);
   set("combat_exp",600000);
   set_skill("parry",160);
   set_skill("dodge",160);
   set_skill("force",160);
   set_skill("strike",160);
   set_skill("hanbing-zhang",160);
   set("jiali",100);
   set("inquiry",([
      "长生诀":"你知道长生诀在哪里吗？快告诉本帅，有重赏的！\n",
      "石龙":"据说石龙这小子很狡猾，我的行踪你可不要泄露给他！\n",
      "徐子陵":"什么？我从不认识这些无名小卒的！\n",
      "寇仲":"什么？我从不认识这些无名小卒的！\n",
      "贞嫂":"据说她包子做的很好，你去给我买点包子回来吧！\n",
      ]));
    setup();
   ob=children("/d/quest/csj/npc/obj/baojia");
   if(sizeof(ob)<=5)
   carry_object(__DIR__"obj/baojia")->wear();
  
}


int accept_object(object who,object ob)
{
  command("hoho "+who->query("id"));
  return 1;
}
