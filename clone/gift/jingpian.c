#include <ansi.h>

string give_gift(); 
private mixed *story = ({          
        "某日，rzy 在家中踱来踱去。",
        "“到底找谁走个后门才能竞到这个项目呢？……”",
        "“啊！有了”",
        "扬州醉花楼，rzy 正在大宴 fhq。 ",
        "rzy ：“您看，这个条子，只要您批示了，就帮了我的大忙啦！”",
        "fhq：“好说好说，喝，喝！” ",
        "酒过三巡……菜过五味…… ",
        "rzy：“您看……，这个条子……”",
        "fhq（醉眼朦胧）：“签……签……没问题。”",
        "说罢fhq接过条子龙飞凤舞签了两个大字。",
        "rzy大喜，拿回条子一看，上书两个大字——“好酒”！",
        "“啪”的一声，rzy 的眼睛掉在地上跌碎了。",
        
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
        STORY_D->give_gift("/clone/quest/jingpian.c", 1,
                           HIM "\n“啪”的一声一个镜片掉到你面前。\n\n" NOR);
        return HIM "一个神秘的镜片在江湖出现了。\n" NOR;
}
