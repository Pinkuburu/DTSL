inherit ROOM;
void create()
{
	int time;
	object ob;
	set("short","房间");
	set("long", @LONG
这里是发放和氏璧的房间。目前设定每隔六个小时和氏璧出
现一次。
LONG);
        time=uptime();
        if((time/3600)%9==0){
        ob=new(__DIR__"heshibi");
        CHANNEL_D->do_channel( this_object(), "rumor","据说和氏璧出现在江湖之中了。\n");
        ob->move("/d/chanyuan/tongdian");}
	setup();      
}
