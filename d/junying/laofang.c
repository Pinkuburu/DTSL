//牢房laofang.c
#include <ansi.h>;
inherit ROOM;
void create()
{
set("short","牢房");
set("long",@LONG
这里是牢房。这里光线昏暗，四周墙壁冰凉，极为厚实。地上散落着一
些烂稻草，湿忽忽的，散发着一股令人作呕的臭味。角落里蜷缩着几个囚犯
看样子快不行了，脚边摆着一只破碗，里面有些霉饭。几只硕鼠肆无忌惮的
来回游荡。
LONG);
setup();
}
void init()
{
object me;
me=this_player();
remove_call_out("kickout");
call_out("kickout",30,me);
}
int kickout(object me)
{
message_vision(HIY"看守对$N说：“你不是奸细，你可以走了！”\n"NOR,me);
me->move(__DIR__"showroom");
message_vision(HIY"$N被丢到了校场上。\n"NOR,me);
return 1;
}
