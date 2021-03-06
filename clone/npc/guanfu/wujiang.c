// wujiang.c 武将
// 标准武将 by Looklove@SJ for all area

inherit NPC;
#include "guanbing.h"

void create()
{
        set_name("武将", ({ "wu jiang", "wujiang", "wu", "jiang" }));
        set("gender", "男性");
        set("shen_type", 1);
        set("no_quest", 1);
        set("no_steal", 1);
        set("no_get", 1);
        set("attitude", "peaceful");
        set("long", "他站在那里，的确有说不出的威风。\n");

        set("age", 25 + random(30));
        set("str", 25 + random(5));
        set("dex", 20);
        set("con", 22 + random(5));
        set("int", 16);

        set("jiali", 20 + random(20));
	set("combat_exp", 75000+random(15000));

        set_skill("cuff", 70);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("taizu-quan", 70);
        map_skill("cuff","taizu-quan");
        prepare_skill("cuff","taizu-quan");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);

        set("chat_chance_combat", 2);
        set("chat_msg_combat", ({
                "武将大喝道：大胆刁民，竟敢造反不成？\n",
                "武将大喝道：来人！给我把这个反贼拿下！\n",
        }));
	set("inquiry", ([
		"朝廷":"朝廷的事情也是你打听的嘛？\n",
		"官府":"哼，老子就是官府！\n",
		"王法":"哼，老子就是王法！\n",
	]));
        setup();
        carry_object(BINGQI_D("sword"))->wield();
        carry_object(ARMOR_D("armor"))->wear();
        carry_object(ARMOR_D("ruanxue2"))->wear();
}
