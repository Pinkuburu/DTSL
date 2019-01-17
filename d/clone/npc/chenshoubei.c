
inherit NPC;

void create()
{
   set_name("陈守备",({ "chen shoubei","chen","shoubei"}) );
        set("gender", "男性" );
        set("age",38);
        set("long","这就是总管扬州的陈守备。\n");
        set("inquiry",([
         "田文":"这个废物，被人偷了东西都不知道！\n",
         "宇文化及":"宇文大帅正命我追查偷长生诀的小偷，这几天可累坏了。\n",
         "徐子陵":"这个小贼，偷人东西差点害的我头颅不保，抓住他一定好好整治他！\n",
         "寇仲":"这个小贼，偷人东西差点害的我头颅不保，抓住他一定好好整治他！\n",
         ]));
        set("chat_chance",20);
        set("chat_msg",({
         (:random_move:),
         "陈守备高声喝道：都闪开，闪开了！本官正在追查小偷，阻拦的一律格杀勿论！\n",
         "陈守备高声道：有谁看到徐子陵和寇仲两个小贼，向本官举报重重有奖！！\n",
        }));
        set("combat_exp",80000);
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("force",80);
        set_skill("blade",80);
        
    setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}

