
inherit ITEM;

void create()
{
   set_name("手卷", ({"shou juan","juan"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "这是一个手卷，上面记录着碧秀心的遗言。\n");
     set("unit", "个");
     set("hj_bsy_quest_obj",1);
     set("no_save",1);
     
   }

}

