// /cmds/wiz/sed.c
//
// lanxin@jianghu

inherit F_CLEAN_UP;
inherit F_SED;				// 继承编辑功能
inherit F_CMD;


int main(object me, string arg)
{
	string file;
	object ob;
	
	if (in_edit(me)) return notify_fail("你已经在使用编辑器了。\n");
	if (!arg) return notify_fail("指令格式：me <档名>|<物件名>\n");
	
	seteuid(geteuid(me));
	file = resolve_path(me->query("cwd"), arg); // 取得档名
	if (file_size(file) < 0)
	{	// 新档
		ob = present(arg, me);	// 检查身上的物件
		if (!ob) ob = present(arg, environment(me)); // 检查房间里的物件
		if (ob && me->visible(ob))
			file = base_name(ob) + ".c"; // 取得物件的档名
	}
	
	start_edit(file);		// 呼叫编辑器，开始编辑
	return 1;
} // main()


int  help(object me)
{
	write(@HELP
指令格式：sed <档名>|<物件名>

利用此一指令可直接在线上编辑档案，详细说明请看编辑器内的线上辅助说明。

相关指令：edit、update。
HELP
		);
	return 1;
} // help()
