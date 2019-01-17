//��ɳ����
//�м�-->�ռ��书��

inherit SKILL;
#include <ansi.h>

mapping *action=({
 ([ "action":"$N��������ÿһ��������������һ���������к;����ĺ�Х���������ҵ�������֯����â��
�䣬���ؼ汸������,��һ�������־�����",
    "apply_factor": 2,
    "name" : "���־�",
    "damage_type":"����",
  ]),
  ([ "action":"$Nһ�С����־�������ľ�������$NΪ������ɳĮ����Ŀ񱩷�ɳ�㣬����$N���Ƚ�����������
��֮����$nϮȥ��",
    "apply_factor": 5,
    "name" : "���־�",
    "damage_type":"����",
  ]),
  ([ "action":"$Nһ����Х������һ�䣮�ó���ɳ������ĵ��ˣ�������$n��ȥ�����ǿ�ɳ����еġ���ɳ������",
    "apply_factor": 10,
    "name" : "��ɳ��",
    "damage_type":"����",
  ]),
  ([ "action":"$w����ջ���һ����������ζ�������˰�����Ĺ켣���仯����ĳ�$n������������",
    "apply_factor": 7,
    "name" : "���־�",
    "damage_type":"����",
  ]),
  ([ "action":"$N��ǰ���ˣ�$w��ѭһ�������Ļ��߹켣����$nնȥ,��һ�� �����־�����",
    "apply_factor": 6,
    "name" : "���־�",
    "damage_type":"����",
  ]),

});   

string *parry_weapon=({

"$N����$wר����·����ȫ���˼��Լ��İ�ȫ���͵ؼ�ס��$n��$v��\n",
"$N��ͬƴ��һ�㣬$w��ǰһ�ܣ���ס��$n��$v��\n",
"$N�ͺ�һ��������$wһ��һ������Ȼ��ס��$n��$v��\n",
"$N����$w����һת�����һ���׹�Χס�Լ�����$n��$v�������棡\n"

});

string *parry_hand=({

"$N����$wһ�ƣ�����һ�����磬$n���ò��ջ���ʽ���˿�����\n",
"$N����Ϊ�أ�����$w������$nնȥ��$n���ò��ջ���ʽ��Ծ���㿪��\n",
"$Nһ�����ң�һ������һ��ֱ�������������Ȼ��$n�Ľ�����Ϊ���С�\n",
"$N�ӵ����һն��$n�Ľ������ɵñ�ǣ����ȥ��$n����һ������æ���˿�����\n"

});

string query_parry_action(object me,object victim)
{
   if(victim->query_temp("weapon"))
    return parry_weapon[random(sizeof(parry_weapon))];
   return parry_hand[random(sizeof(parry_hand))];

}


mapping query_action(object me,object weapon)
{
   
   int i, level,temp;
	object target;
	object *enemy;

	level = me->query_skill("kuangsha-daofa",1);

	enemy = me->query_enemy();
	if(sizeof(enemy)>0)
	{
       target = enemy[random(sizeof(enemy))];

 	if ( random(10)>=7 && me->query("force")>500 ) {
		if ( me->query_skill("yanyang-dafa",1)>=200 
				&& me->query_skill("kuangsha-daofa",1)>=200 
				&& !me->query_temp("apply_at")) {
			me->set_temp("apply_at",1);
			call_out("autopfm",1,me,target);
		}
	}	
	}
      
   return action[random(sizeof(action))];
 

}
void autopfm(object me,object target)
{
	object weapon;
	int i;
	int damage;
	if(!me) 
		return;
	if(!target){
		me->delete_temp("apply_at");
		return;
	}	
	if(!me->is_fighting(target)){
		me->delete_temp("apply_at");
		return;
	}
	
	me->add("force",-50);
	if (me->query("force")<0) me->set("force",0);

	weapon = me->query_temp("weapon");	
	if(!weapon){
		me->delete_temp("apply_at");
		return;
	}
	damage=me->query("apply_points");
  
 	message_vision(HIY"\n$N"+HIY+"������"+weapon->query("name")+HIY"������һƬҫ�۵Ĺ⻪��$n"+HIY+"�������Ի�Ĳ�֪���룡\n"+CYN+"$n"+CYN+"һ��û����͸�$N"+CYN+"���������£�"NOR,me,target);
	me->add_temp("apply/damage",damage);
  COMBAT_D->do_attack(me,target,weapon,0,1);  
  COMBAT_D->do_attack(me,target,weapon,0,1);  	
  me->add_temp("apply/damage",-damage);
  me->delete_temp("apply_at");
  	
  if(!me->is_fighting(target))
    me->delete_temp("apply_at");
  return;

}

mapping *query_all_action(object me)
{
return action;	
}

string query_type()    
{                      
	return "blade";
}
string query_base()  
{
	return "blade";
}

string *query_perform()
{
   return ({"kuangsha"});
}

int valid_learn(object me)
{

        int i = (int)me->query_skill("kuangsha-daofa", 1);
	object weapon;
        if (i>199) return notify_fail("ѧ��ֻ��ѧ�������ˣ�ʣ�µ�Ҫ�����Լ���ϰ�ˡ� \n");
        if(!objectp(weapon=me->query_temp("weapon"))||
           (string)weapon->query("skill_type")!="blade")
			return notify_fail("�����޵������ѧϰ��ɳ������\n");
	return 1;
}
int practice_skill(object me)  
{
   object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
 
 return 1;  


}

mapping query_select_action(int i)
{
	if((i)>sizeof(action))
		return 0;
	else return action[i-1];
}

int skill_damage(object me,object victim)
{
  if(me->query("perform_quest/kuangsha"))
  return 200;
  return 80;
}
