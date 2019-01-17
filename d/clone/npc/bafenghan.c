
inherit NPC;

void create()
{
   int i;
   object *ob;
   set_name("跋锋寒",({ "ba fenghan","ba","fenghan"}) );
        set("gender", "男性" );
        set("age", 32);
   set("long", "这是西突厥的勇士跋锋寒，也是胆敢向毕玄挑战的人。\n");
       
   set("combat_exp",1000000);
   set("per", 24);
   set("cor",30);
   set("str",30);
   set("jiali",200);
   set_temp("apply/armor",50);
   set_temp("apply/dodge",50);
   set_temp("apply/damage",50);
   set_skill("sword",200);
   set_skill("dodge",200);
   set_skill("parry",200);
   set_skill("force",200);
   set_skill("toutian-jianfa",200);
   
   set("max_kee",2000);
   set("max_gin",2000);
   set("max_sen",2000);
   set("max_force",2000);
   set("force",2000);
   set("inquiry",([
     "风湿寒":"呵呵，你也知道这个我这个绰号了？是寇仲和徐子陵给我起的。\n",
     "寇仲":"我好久没看到他了，不知道他现在怎么样了。\n",
     "徐子陵":"据说他去了长白山，不知是真是假。\n",
     ]));
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   ob=children(__DIR__"obj/toutian-jian");
   for(i=0;i<sizeof(ob);i++)
     if(environment(ob[i])&&userp(environment(ob[i]))){
     tell_object(environment(ob[i]),"你手中的"+ob[i]->query("name")+"被它的主人收回去了！\n");
     if(ob[i]->query("equipped"))
      ob[i]->unequip();
     destruct(ob[i]);}
     else if(environment(ob[i])){
     tell_object(environment(ob[i]),ob[i]->query("name")+"被一阵风卷走了。\n");
     destruct(ob[i]);}
     else destruct(ob[i]);
   carry_object(__DIR__"obj/toutian-jian")->wield();
  
}

