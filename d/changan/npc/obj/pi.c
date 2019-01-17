
 
inherit ITEM;

void create()
{
   set_name("香蕉皮", ({"banana"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个香蕉皮。\n");
                set("unit", "个");
                
				call_out("rid",120,this_object());
        }
}
void init()
{
	object ob;
	ob=this_player();
	if(ob&&query("use")<4){
	  add("use",1);
	  call_out("go",1,ob);}
	return;
}

void rid(object ob)
{
	destruct(ob);
	remove_call_out("rid");
	return;
}

void go(object ob)
{
	mapping exits;
	string *d;object where;
	exits=environment(ob)->query("exits");
    if( !mapp(exits) || !sizeof(exits) ){ remove_call_out("go");return;}
	d=keys(exits);
	message_vision("$N踩到了香蕉，划了一跤！\n",ob);
	where=load_object(exits[d[random(sizeof(d))]]);
	ob->move(where);
	remove_call_out("go");
	return;
}