//baimo by 2001/9/24

inherit BULLETIN_BOARD;

void create()
{
        set_name("skills研究专栏", ({ "board" }) );
        set("location", "/d/wiz/wizroom4");
        set("board_id", "skill_b");
        set("long", "对skills有意见可以在这里post，不许灌水，违者严惩。\n" );
        setup();
        set("capacity", 380);
        
}


