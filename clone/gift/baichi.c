#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "yanyan带着巫师们去野外郊游。",
        "看到春风拂绿，杨柳抽枝，yanyan不禁想起一个问题，于是问道：",
        "“大家知道如何识别风向吗？”",
        "“我知道！”yanzi一边回答一边从从地上捡起一片树叶向空中抛去。",
        "“捡一片东西往空中一抛，看它往那边飘，不就知道了吗。”",
        "“嗯，很好。”yanyan表扬道，“那还有谁愿意再给大家示范一下，看看现在刮的是什么风？”",
        "“我。”fhq自告奋勇走了出来，变出了一百两黄金向空中抛去……",
        "“报告，现在刮的是上下风！” …………",
        
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
        STORY_D->give_gift("/clone/money/gold.c", 1,
                           HIM "\n“蓬”的一声一百两黄金掉到你面前。\n\n" NOR);
        return HIM "一百两黄金在江湖出现了。\n" NOR;
}
