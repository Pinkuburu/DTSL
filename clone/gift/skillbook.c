#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "大唐武功理论考场，考官，真冰河，考生，wlq，lying，等人。",
        "liying：真冰河有点口吃的哦... ...",
        "考试中，身为监考人员的口吃阿弟真冰河小心的在寻场。",
        "突然地发现有个考生在看小抄！",
        "他很生气指著作弊考生说：你…你…你…你…你…你…你…你…你…竟敢作弊？！给我站起来！",
        "语毕，九个考生站了起来…",
        "wlq惊慌之下把作弊的纸团丢到了地上……",
        
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
        STORY_D->give_gift("/clone/quest/skillbook.c", 1,
                           HIM "\n“蓬”的一声一本书掉到你面前。\n\n" NOR);
        return HIM "一本武学秘籍在江湖出现了。\n" NOR;
}
