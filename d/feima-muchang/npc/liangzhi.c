
inherit NPC;

void create()
{
   set_name("����",({ "liang zhi","liang"}) );
        set("gender", "����" );
        set("age", 40);
   set("long", "�����Ƿ����������Ĵ�ִ��֮�ס�\n");
       
   set("combat_exp",400000);
   set("str", 26);
   set("per", 22);
   set("attitude", "peaceful");
   set_skill("unarmed",130);
   set_skill("dodge",130);
   set_skill("parry",130);
   set_skill("strike",130);
   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}
