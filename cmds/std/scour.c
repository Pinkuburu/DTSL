// 在尸体上随机搜到东西。

inherit F_CLEAN_UP;

int main(object me, string arg)
{
     object corpse;
     int i,flag=0;
     object obj;
         
     if(!arg)
     return notify_fail("你要搜查什么东西？\n");
     if(!objectp(corpse=present(arg,environment(me))))
     return notify_fail("你周围没有这个东西。\n");
     if(!corpse->is_corpse())
     return notify_fail("那个东西不是尸体，不能搜查！\n");
     /*
     if(corpse->query("killed_by")!=me->query("id"))
     return notify_fail("这个不是你杀的尸体，不能从里面搜东西。\n");
     */
     if(corpse->query("have_scoured"))
     return notify_fail("这个尸体已经被搜过了，没有什么东西了。\n");
     corpse->set("have_scoured",1);
     message_vision("$N蹲下来，在尸体里翻了几下。\n",me);
     i=random(5);
     if(random(100)<70||corpse->query("player_corpse")) i=0;
     if(i>0) flag=1;
     while(i--){
     	switch(random(2)){
     	   case 0: obj=new(__DIR__"misc/tiekuang");break;
     	   case 1: obj=new(__DIR__"misc/medicine");
     	}
     	obj->set_status(me);
     	obj->move(corpse);
     }
     if(flag)
     tell_object(me,"尸体里好象有什么东西。\n");
     else
     tell_object(me,"尸体里什么也没有。\n");
    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : scour corpse

这个指令让你从尸体中寻找一些物品，如矿石、药材等。而从尸体中
发现的矿石、药材，经常会比开采到的、挖到的好。
从尸体中得到物品是有几率的，不是每次都能得到，而且每个尸体只
能搜一次。

HELP
    );
    return 1;
}
