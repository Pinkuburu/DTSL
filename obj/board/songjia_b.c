
inherit BULLETIN_BOARD;

void create()
{
        set_name("宋家堡留言版", ({ "board" }) );
        set("location", "/d/lingnan/door");
        set("board_id", "songjia_b");
   set("long", "这是供宋家堡的人使用的留言版.\n");
  
        setup();
        set("capacity", 280);
        replace_program(BULLETIN_BOARD);
}

