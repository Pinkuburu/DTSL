#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "听说 subzero 得病之后，tott和valkyrie去看望 subzero。 ",
        "当tott和subzero正聊天的时候，valkyrie闲着无聊，看见桌上有一碗花生。",
        "valkyrie改不了嘴搀的毛病，就开始吃花生。",
        "当tott和subzero聊完和subzero告辞。",
        "valkyrie对subzero说：多谢你的花生。 ",
        "subzero：不用谢呀，最近牙不好，我只能把外面的巧克力吸掉，的花生豆咬不动。",
        "valkyrie：...... ",
       
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
        STORY_D->give_gift("/clone/quest/huasheng.c", 1,
                           HIM "\n“啪”的一声，一粒花生掉在你的面前。\n\n" NOR);
        return HIM "一粒花生在江湖出现了。\n" NOR;
}
