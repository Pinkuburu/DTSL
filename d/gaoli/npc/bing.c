// 大唐双龙传
//bing.c 小兵
 
inherit "/std/guard.c";

void create()
{
        set_name("小兵", ({ "xiao bing", "bing" }));
        set("age", 18+random(10));
        set("gender", "男性");
        set("long","这是一名高丽士兵，这些士兵隶属御林军，是士兵中的精锐。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("combat_exp", 80000);
        set("max_kee", 400);
        set("max_mana", 200);
        set("max_sen", 400);
        set("max_force", 200);
        set("force", 200);
        set("force_factor", 10);
        
        set("guard","gaoli");
        set_this_skills("middle");
        set_all_skill(this_object(),160);
        
        setup();
        
}
