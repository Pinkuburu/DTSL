
inherit ROOM;
#include <ansi.h>
#include <job_money.h>
#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"gangkou"
#define TO "/d/gaoli/gangkou"
#include "/std/shiproom.c";
void create ()
{
  set ("short","港口");
  set ("long", @LONG
这里扬州的东门的港口。扬州是中原一大繁华城市，所以这里的港
口也是非常的热闹。据说从这里可以坐船到高丽国。这里也有很多外国
来的商人，非常热闹。这里有一个牌子(pai).
LONG);

  set("exits", ([ 
      "west":"/d/yangzhou/dongmen",
      ]));
  set("item_desc",([
  "pai":"每次船费纹银十两，银票不收。\n",
  ]));
  set("valid_startroom", 1);
  set("outdoors","yangzhou"); 
  set("no_duhe",1);
  setup();
 
}


int valid_leave(object ob,string dir)
{
  if(dir=="enter"){
  switch(MONEY_D->player_pay(ob,1000)){
  	case 0:return notify_fail("水手说道：你的船钱不够啊!\n");
  	case 2:return notify_fail("水手说道：银票我们找不开的！\n");
  	default:break;}
   return ::valid_leave(ob,dir);}	
   return ::valid_leave(ob,dir);
}
