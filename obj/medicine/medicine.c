
inherit ITEM;

#include <ansi.h>

string *lev=({
BLU"极少"NOR,HIB"很少"NOR,CYN"少量"NOR,GRN"较多"NOR,
HIC"很多"NOR,HIY"大量"NOR,HIG"极多"NOR,HIW"罕见"NOR,

});

void create()
{
        set_name("药", ({ "medicine" }) );
        set_weight(10);
        set("unit", "包");
	set("long","这是一棵草。\n");
        setup();
}

string long()
{
  string longs;
  mapping m_types;
  string *eff_types,msg;
  int i,div=1;
  
  longs=query("long");
  
  m_types=query("heal_up");
  if(!mapp(m_types))
   return longs;
  
  eff_types=keys(m_types);
  
  longs+="功效：\n";
  
  for(i=0;i<sizeof(eff_types);i++)
   if( m_types[eff_types[i]]>0){
     if(eff_types[i]=="暂时增加内力"||
        eff_types[i]=="暂时增加内力上限"
       )
      div=300;
     else
     if(eff_types[i]=="暂时增加防御"||
        eff_types[i]=="暂时增加命中"
       )
      div=10; 
     else
     if(eff_types[i]=="暂时增加臂力"||
        eff_types[i]=="暂时增加根骨"||
        eff_types[i]=="暂时增加身法"||
        eff_types[i]=="暂时增加悟性"
       )
      div=2; 
     else
     if(eff_types[i]=="增加内力上限")
      div=1; 
     else
     if(eff_types[i]=="增加臂力"||
        eff_types[i]=="增加根骨"||
        eff_types[i]=="增加身法"||
        eff_types[i]=="增加悟性"
       )
      div=1; 
     else
     if(eff_types[i]=="增加经验"||
        eff_types[i]=="增加潜能"
       )
     div=15;
     else
     div=75;
    longs+="【"+eff_types[i]+"】【"+lev[m_types[eff_types[i]]/div>sizeof(lev)-1?sizeof(lev)-1:m_types[eff_types[i]]/div]+"】\n";
           
   }
  return longs;
  
}