inherit ITEM;

void create()
{
	set_name("下棋指南",({"xiaqi zhinan","xiaqi","zhinan"}) );
	set("long","请用 read zhinan 阅读怎样在品棋亭下棋。\n");
	set_weight(5);
	set("unit","本");
	set("value",100);
}

void init()
{
	add_action("do_read","read");
}

int do_read(string arg)
{
	object me = this_player();
	string msg = "欢迎到华山「下棋亭」来下棋！\n" +
"

在这里您可以下围棋或五子棋，以下告诉您下棋的步骤：
一、先找好对手，然后分别用 sit black 和 sit white 入座；
二、使用 new 开始一盘新的棋局：new [-5] [-b(numbers)] [-h(numbers)]
    其中 -5 代表下五子棋，不选即为下围棋；
　　-b指定所用棋盘的大小；
    -h指定让子的数目；
　　例如：
　　围棋：new
　　十五乘十五的五子棋：new -5 -b15
　　让九子围棋：new -h9
三、使用 play 轮流走棋：例如 play d4 等等。
四、使用 refresh观看棋盘。
五、使用 undo 悔棋。(目前只提供五子棋的悔棋功能。)
六、规则。任何一方下棋考虑时间不得超过 60 秒，超过则自动认输。
          如果想向对方认输，可以使用 surrender。
          下棋时不能走动，如果在棋盘没有结束时离开，要使用leave，
              则算自动认输，扣罚输五盘棋局。
七、段数。每胜 100 盘棋算 1 段。对手之间的棋局胜数如果超过 10 局，
          则胜方不加胜数，而负方继续加负数。
八、可以使用 check 来看自己的下棋水平。
";
	if(arg=="zhinan" || arg=="xiaqi zhinan") {
		tell_object(me,msg);
		return 1;
	}
	 else return 0;
}

