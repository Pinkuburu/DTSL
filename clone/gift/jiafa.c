#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "说大唐开发了之后，弄得很多人都不爽，所以他们想暗杀这些巫师... ...",
        "lying 听了就特别害怕，赶忙去了美容院做了美容。",
        "出来的时候已经变成一个长发美女了！",
        "走在街上，看见一个要饭的老太太... ...",
        "就给了她100块钱，问她你知道我是谁吗？",
        "老太太看了看他，说 lying！",
        "他听了吓坏了，连忙又去了美容院，第二次出来，又碰到那个老太太。",
        "他又过去问了同样的问题，这次老太太连看也没看，就说lying！",
        "他毛了，你怎么认出我的，老太太连忙说，嘘，小声点，我是 yanyan...",
        "一个假发从lying的头上飞走了！！",
              
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
        STORY_D->give_gift("/clone/quest/jiafa.c", 1,
                           HIM "\n“蓬”的一声一个假发掉到你面前。\n\n" NOR);
        return HIM "一个假发在江湖出现了。\n" NOR;
}
