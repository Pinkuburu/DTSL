
inherit BULLETIN_BOARD;

void create()
{
        set_name("长安李阀留言版", ({ "board" }) );
        set("location", "/d/cahc/chengqingdian");
        set("board_id", "lifa_b");
   set("long", "这是长安李阀专用的留言板.\n");
  
        setup();
        set("capacity", 380);
        replace_program(BULLETIN_BOARD);
}

