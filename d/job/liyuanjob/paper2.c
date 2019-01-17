
#include <ansi.h>

inherit ITEM;

int do_pingluan(string arg);

void create()
{
        set_name("安抚令", ({ "paper" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "");
                set("no_give",1);
                set("no_drop",1);
                set("no_sell",1);
                set("value", 300);
                set("material", "wood");
        }

        setup();
}

string long()
{
  return "\n"+
  "※※※※※※※※※※※※※※※※※※\n"+
  "这是一张官府发的安抚文书，上面写着:  \n"+
  "据说最近"+query("target_name")+"聚众做乱,\n"+
  "特命安抚大使去安抚平乱。          \n"+
  "※※※※※※※※※※※※※※※※※※\n";
}

void init()
{
  add_action("do_pingluan","pingluan");
}

int do_pingluan(string arg)
{
  object ob;
  object target;
  int cost;
  
  ob=this_player();
  if(!arg)
  return notify_fail("你要平定谁的作乱？\n");
  if(!objectp(target=present(arg,environment(ob))))
  return notify_fail("这里没有这个人！\n");
  if(query("target_place")!=base_name(target))
  return notify_fail(target->name()+"一笑：我没有做什么事，干什么来这里平乱？\n");
  if(ob->query_temp("liyuan_job/step")!=9)
  return notify_fail("你没有权利来平乱！\n");
  
  cost=1500+random(500);
  
  switch(MONEY_D->player_pay(ob,cost)){
    case 0:
    case 2:
    return notify_fail("你身上的钱不足以用来平定反乱！\n");
    break;
    default:break;}
  ob->add_temp("liyuan_job/step",1);
  message_vision("$N笑道：既然李阀主肯为百姓解囊，那百姓还哪有不拥护之理？\n",
                  target);
  tell_object(ob,"你成功地平定了反乱！\n");
  destruct(this_object());
  return 1;
}
  