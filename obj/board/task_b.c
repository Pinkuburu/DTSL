
inherit BULLETIN_BOARD;

void create()
{
        set_name("巫师工作记程版", ({ "task board" }) );
        set("location", "/d/wiz/wizroom5");
        set("board_id", "task_board_b");
   set("long", "这是巫师工作进程记录版。请各位巫师把自己的\n"+
               "工作进程记录到这里，相互配合好。\n");
  
        setup();
        set("capacity",300);
        replace_program(BULLETIN_BOARD);
}

