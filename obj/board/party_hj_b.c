
inherit BULLETIN_BOARD;

void create()
{
	set_name("花间弟子留言板", ({ "board" }) );
	set("location", "/d/luoyang/zhulou");
	set("board_id", "party_hj_b");
	set("long","这是花间派弟子的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
