// by Yanyan.

#include <ansi.h>
#define QUEST_DIR "/doc/quest/"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string file;
	
	if(!arg){
	 cat(QUEST_DIR+"topic");
	 return 1;}
	file=QUEST_DIR+arg;
	if(file_size(file)<=0)
	return notify_fail("没有这个迷题的说明文件。\n");
	me->start_more(read_file(file));
        write("\n");
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quest
 
这个指令可以显示出大唐双龙目前开放的迷题。
HELP
        );
        return 1;
}
