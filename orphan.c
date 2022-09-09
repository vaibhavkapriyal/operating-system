#include <stdio.h>
#include <unistd.h>

int main()
{
   	int pid=fork();
   	
   	if(pid>0)
   	{
   		printf("parent process\n");
   	}
   	else if(pid==0)
   	{
   		sleep(10);
   		printf("chlid process\n");
   	}
   	
   	return 0;
}
