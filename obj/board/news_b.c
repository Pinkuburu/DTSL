
inherit BULLETIN_BOARD;

void create()
{
        set_name("新闻公告版", ({ "board" }) );
        set("location", "/d/wiz/wizroom");
        set("board_id", "news_b");
   set("long", "这是新闻公告版，巫师的更新说明请写在这里。\n");
  
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}

