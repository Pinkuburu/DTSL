
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"huafang"
#define TO __DIR__"matou"
#include "/std/shiproom.c";
void create ()
{
  set ("short",HIR"画"HIG"舫"NOR);
  set ("long", @long
这里是扬州最著名的画舫，长数十尺，十分巨大，从里面隐约传来
歌舞丝竹之声。登船的地方正好是画舫的船头。
long);

  set("exits", ([ 
  "north":__DIR__"chuancang",
         ]));

  set("valid_startroom", 1);
  set("outdoors","yangzhou");
  setup();
 
}

