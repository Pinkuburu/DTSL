
inherit ROOM;


void create ()
{
  set ("short","回龙寺院");
  set ("long", @LONG
这里就是回龙寺的大院。正前方是回龙寺的大熊宝殿，东边是一排
厢房，西边场地宽阔，似乎是寺内武僧习武的地方。这里显得有些冷清，
看来回龙寺的香火不是很好。
LONG);

  set("exits", ([ 

  "out":__DIR__"miaodoor",
  "enter":__DIR__"baodian",
      ]));

  set("valid_startroom", 1);
  set("outdoors","lingnan");
  setup();
 
}

