#include <stdio.h>
#include <unistd.h>
int main(void){
	int x =100;
	int pid = fork();
	if( pid == 0 ){
		printf("value of x in child process is %d\n",x);
		x = 50;
		printf("value of x in child process is changed to %d\n",x);
	}
	else {
		printf("value of x in the parent process is %d\n",x);	
			
	}

	return 0;
}
