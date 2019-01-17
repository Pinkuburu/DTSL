#include <ansi.h>
// #include <job_money.h>
inherit ITEM;
mapping name=([
RED"红花"NOR:"honghua",
YEL"陈皮"NOR:"chenpi",
HIY"人参"NOR:"renshen",
GRN"当归"NOR:"danggui",
HIC"雪莲"NOR:"xuelian",
BLU"生地"NOR:"shengdi",
MAG"何首乌"NOR:"heshouwu",
]);

string *heals=({"气血","精神","精血"});

void create()
{
   string *n;int i;
   string *w;
    
   n=keys(name);
   i=random(sizeof(n));
   set_name(n[i],({name[n[i]]}));
   set_weight(500);
   
   set("unit", "颗");
   set("no_sell",1);
   set("nogive_player",1);
   set("no_save",1);
   set("long","这是一颗草药，它能用来炼制药物。\n");
   set("medicine_type",([
         "type" :heals[random(sizeof(heals))],
         "gongxiao" :10,
         ])); 
              
   setup();
   
}

string long()
{
  return query("long")+"\n"+"具有治疗"+query("medicine_type/type")+"的功效。\n";
}
