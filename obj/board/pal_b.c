
inherit BULLETIN_BOARD;

void create()
{
        set_name("留言版", ({ "board" }) );
        set("location", "/d/yangzhou/zuihualou");
        set("board_id", "pal_b");
   set("long", "有什么话要说,有什么意见,请留言吧!\n");
  
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

