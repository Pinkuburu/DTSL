//by dsm 5/1/99

inherit F_CLEAN_UP; 
int main(object me, string arg) 
{ 

	int i, j; 
	string dir; 
	mixed *file; 
         
        seteuid( geteuid(me) ); 

	dir = resolve_path(me->query("cwd"), arg); 
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/"; 
	file = get_dir(dir, -1); 
	if( !sizeof(file) ) {
		if (file_size(dir) == -2) return notify_fail("目录是空的。\n"); 
			else return notify_fail("没有这个目录。\n"); 
		} 

	i = sizeof(file); 

	for(i=0, j = sizeof(file); i<j; i++) 
	{ 
		rm(dir+file[i][0]); 
                } 
	rmdir(dir);
	write("目录" + dir + "   删除了.\n"); 

	return 1; 
} 
