
inherit BULLETIN_BOARD;

void create()
{
        set_name("巫师留言版", ({ "board" }) );
        set("location", "/d/wiz/wizroom2");
        set("board_id", "wiz_b");
   set("long", "这是巫师专用的留言板.\n");
  
        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}

