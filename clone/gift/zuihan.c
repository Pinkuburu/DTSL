#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "一日，rzy 去酒馆喝酒，看见一客人正和服务生纠缠。 ",
        "服务生说：你真的把钱袋丢了？",
        "客人回答：真的，不骗你。",
        "服务生：那好，你去到门口蹲下吧。 ",
        "客人随后就到门口蹲了下来，谁知服务生一脚就把客人踢了出去。",
        "rzy 看到后，马上要了一杯XO喝了下去，高声喊到：喂，我也没有带钱。",
       
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
        STORY_D->give_gift("/clone/quest/zuihan.c", 1,
                           HIM "\n一个醉汉摇摇晃晃地走了过来。\n\n" NOR);
        return HIM "一个醉汉在江湖出现了。\n" NOR;
}
