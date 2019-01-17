// Room: /d/longyan/tenting.c

inherit ROOM;

void create()
{
        set("short", "十里亭");
        set("long", @LONG
这里是一座路边小亭，似乎已经很多年没有人来
打扫过了。亭子的墙上画着一幅，似乎是一个长发女
子，旁边似乎还有一首诗（poem）。过了亭子往东就
是黑松山了。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road1",
]));
set("item_desc", ([
	"poem":"\n只  对  寸  十\n\n羡  月  寸  里\n\n鸳  形  青  平\n\n鸯  单  丝  湖\n\n不  望  愁  霜\n\n羡  相  华  满\n\n仙  护  年  天\n\n\n",
	]));
        setup();
        replace_program(ROOM);
}
