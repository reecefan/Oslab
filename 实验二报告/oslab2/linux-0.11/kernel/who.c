#define __LIBRARY__
#include <unistd.h>
#include <errno.h>
#include <asm/segment.h>
#include <string.h>
char username[64]={0};
int sys_iam(const char* name){
 int i=0;
 while(get_fs_byte(&name[i])!='\0')
	i++;
 if(i>23)
  return -EINVAL;
   i=0;
 while(1){
   username[i] = get_fs_byte(&name[i]);
     if(username[i] == '\0')
	 break;
       i++;
    }
    return i;
}
int sys_whoami(char* name,unsigned int size){
 int i,len;
 len=strlen(username);
 if (size<len)
 return -1;
 i=0;
 while(i<len){
  put_fs_byte(username[i],&name[i]);
  i++;
 }
 return i;
}
