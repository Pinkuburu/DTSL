
#include <ansi.h>
inherit ROOM;
int do_yell();

void create ()
{
  set ("short",HIY"吊桥"NOR);
  set ("long", @LONG
这里是出入飞马牧场的吊桥。桥的下面满布尖头木头，若是掉下去
就算神仙在世也是无能为力了。所以出入飞马牧场的人须靠吊桥通行，
这里的确有一夫当关，万夫难渡之势。你可以高声叫(yell)守卫来放下
吊桥。
LONG);
  set("exits",([
	  "southeast":"/d/luoyange/shanlu3",
	  ]));

  set("outdoors","feima");
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
	add_action("do_yell","yell");
}

int do_yell()
{
    int beipan;object me;object where;
    object podao;
	me=this_player();
	where=environment(me);
	beipan=(int)me->query("beipan",1);
	if(beipan>=3)
		return notify_fail("飞马牧场的守卫大声喊道:像你这种多个势力的叛徒,休想进我们飞马牧场!\n");
    if(where->query("exits/enter"))
		return notify_fail("吊桥已经放下来了!\n");
    podao=load_object(__DIR__"podao1");
    if(podao->query("exits/out"))
    return notify_fail("吊桥已经放下来了!\n");
	call_out("do_bridge",5,where);
	message_vision("守卫冲着$N大声道:"+RANK_D->query_respect(me)+",等一下,我这就放下吊桥!\n",me);
	tell_object(where,"只听隆隆声音,吊桥正缓慢的放下来了.\n");
	return 1;
}

void do_bridge(object where)
{   
    object podao1;
	podao1=load_object(__DIR__"podao1");

	tell_object(where,"只听哐当一声,吊桥已经放下来了!\n");
	tell_object(podao1,"只听哐当一声,吊桥已经放下来了!\n");
	podao1->set("exits/out",__DIR__"bridge");
	where->set("can_go",1);
	where->set("exits/enter",__DIR__"podao1");
	remove_call_out("do_bridge");
	call_out("do_close",20,where,podao1);
	return;
}

void do_close(object where,object podao1)
{
	tell_object(where,"只听隆隆声音,吊桥被拉上去了.\n");
	tell_object(podao1,"只听隆隆声音,吊桥被拉上去了.\n");
	where->delete("exits/enter");
	where->delete("can_go");
	podao1->delete("exits/out");
	remove_call_out("do_close");
	return;
}