
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIW"美人扇"NOR, ({ "shan zi","shan" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("value", 500);
set("no_save",1);
     set("rumor",1);
     set("super",5);
     set("material", "iron");
     set("long", HIW"此扇以精钢为骨，扇面由天蚕丝编织而成。一面画有十数个各色神态的美女，
无不惟妙惟肖。另一面单画一人，妩媚妖娆，仔细看去却是那江湖人闻之丧胆
的魔女婠婠！\n"NOR);
     set("wield_msg", HIW"$N"+HIW+"随手招出$n"+HIW+"顺势扇了几下，显出无尽的潇洒风流！\n"NOR);
     set("unequip_msg", HIW"$N"+HIW+"随手一摇，抖出一片扇影，扇影消去$n"+HIW+"已消失不见。\n"NOR);
   }
   init_blade(165,180,180);
   setup();
}
// Edit By Subzero
