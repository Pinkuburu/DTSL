//苍狼诀，突厥派心法。


inherit SKILL;

string query_type()
{
  return "literate";
}

int valid_learn(object me)
{
    if((int)me->query_skill("canglang-jue",1) > 400 )
        return notify_fail("单纯的学习已经无法让你从本质上提高了，自己去领悟精髓吧。 \n");
    return 1;
}

string *query_execute()
{
   return ({"xiao"});
}

string help_action()
{
write(@LONG
    苍狼诀
——————————————————————
    execute:
    execute xiao
——————————————————————
        
LONG);
return "\n";
}
