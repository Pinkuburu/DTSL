

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "“真冰河”饰徐子凌。",
        "“赵七七”饰寇仲。",
        "“夜猫”饰跋锋寒。",
        "话说寇、徐、跋三人盗取了和氏璧.........",
        "在静念禅院的郊外..................",
        "寇仲：妈的，这个和氏璧究竟有什么用？",
        "跋锋寒：“大概把内力注进去就有奇迹发生啦吧？”",
        "于是三人就把内力灌进和氏璧.........",
        "寇、徐、跋：“呵！哈！啊！.........”",
        "不一会儿奇迹真的发生了.........",
        "由于他们的内力过于强大，只听见“啪”的一声，和氏璧飞了出去！",
        "寇、徐、跋：“我靠！！”",
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/quest/heshibi", 1,
                           HIM "\n“啪”的一声一块和氏璧掉到你面前。\n\n" NOR);
        return HIM "听说和氏璧出现在人间了。\n" NOR;
}
