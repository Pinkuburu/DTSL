//Edit By Subzero
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIB"水仙"NOR, ({ "shuixian dao","shuixian","dao" }) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("no_save",1);
     set("rumor",1);
     set("super",5);
     set("value", 100000000);
     set("material", "iron");
     set("no_sell", 1);
     set("long", HIB"只见刀体薄如绸缎，像羽毛般轻柔灵巧，还渗出篮晶晶的莹芒，锋快至\n"+
                    "非是目睹，定不敢相信世间竟会有此筑宝。这就是天刀宋缺收藏的刀中\n"+
                    "极品——水仙。此刀相传为东溟铁匠所做，因其诞生时便杀气四溢，常\n"+
                    "人使用轻者疯癫，重者舞刀力尽而忘，非有德者不能用。被东溟派视为\n"+
                    "奇刀，后在宋阀与东溟交易武器时，作为礼物送与宋缺。宋缺按其特性\n"+
                    "创出天刀八决，再加上奇刀水仙，让人犀利难挡。\n"NOR);
     set("wield_msg", HIC"$n"+HIC+"如同有生命一般，还未等$N"+HIC+"伸手抽出，竟然自己脱鞘一半，\n等侯主人使用。\n"NOR);
     set("unequip_msg",HIB"$N"+HIB+"眼看着刀身晶莹流转的蓝芒，不由感叹：不愧是传说中的奇刀，\n依依不舍地将其收起。\n"NOR);
   }
   init_blade(140,220,220);
   setup();
}
