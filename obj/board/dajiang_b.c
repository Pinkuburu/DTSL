
inherit BULLETIN_BOARD;

void create()
{
        set_name("大江联留言版", ({ "board" }) );
        set("location", "/d/dajianglian/mumen");
        set("board_id", "dajiang_b");
   set("long", "这是大江联专用的留言板.\n");
  
        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}

