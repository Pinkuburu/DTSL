inherit ROOM;
void create ()
{
  set ("short","山路");
  set ("long", @LONG
这里是静念禅院后山的山路。路的两边杂草丛生。不时有花
色斑斓的小蛇从你的脚面滑过。这里能隐隐约约听到山下禅院传
来的诵经声。
LONG);

  set("exits", ([ 
 "northup":__DIR__"shanlu2",
 "southdown":"/d/xingyang/shanlu3",
        ]));
 set("valid_startroom", 1);
  setup();
}
