
inherit BULLETIN_BOARD;

void create()
{
        set_name("飞马牧场留言版", ({ "board" }) );
        set("location", "/d/feima-muchang/door");
        set("board_id", "feima_b");
   set("long", "这是飞马牧场专用的留言板.\n");
  
        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}

