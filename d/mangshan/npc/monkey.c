

inherit NPC;

void create()
{
        set_name("猴子",({ "monkey","hou" }) );
        set("gender", "雄性" );
		set("race","野兽");
        set("age", 13);
        set("long", "这是一野猴子。\n");
        set("kee",200);
		set("gin",200);
		set("sen",200);
        set("limbs",({"头","尾巴","爪子"}));
       
		set("apply/attack",5);
		set("apply/parry",5);
	set("shen_type", 1);
	set("shen", 3000);
       
        set("combat_exp", 120000);
        
		
		set("hand",({"zhua"}));
        set_skill("zhua",10);
		
	
	
        setup();

        
}

