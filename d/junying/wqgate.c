//兵器库大门wqgate.c
inherit ROOM;
void create()
{
set("short","兵器库大门");
set("long",@LONG
你来到了兵器库大门口。这里存放着所有的兵器，从海盗和盗贼那收缴
的兵器也放在这里。大门口站着两个看守，检查进进出出取武器的人。这不
，刚好有个海盗派来的奸细被抓住了，他试图乔装进入，窃走兵器。你还是
赶快走吧，别被当奸细抓走了。
LONG);
set("exits",([
"west":__DIR__"showroom",
"south":__DIR__"bingying",
]));
set("objects",([
__DIR__"npc/kanshou":2,
]));
setup();
}
