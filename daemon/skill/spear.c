inherit SKILL;

string perform_action_file(string action)
{
	return __DIR__"spear/"+action;
}

int valid_learn(object me)  
{
        int i = (int)me->query_skill("spear", 1);
        if (i>400) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ������ˡ� \n");
        return 1;
}



string query_type()
{
  return "base";
}