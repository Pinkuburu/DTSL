//基本知识类型
//如读书识字，媚功幻术等。


inherit SKILL;

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
   if(me->query_skill("literate",1)>400
    &&!me->query_temp("mark/literate",1))
    return notify_fail("这项技能你还是到书院学习吧！\n");
   
  return 1;
}

string perform_action_file(string action)
{
	return __DIR__"literate/"+action;
	
}