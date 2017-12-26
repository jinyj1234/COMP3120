#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void){
	int pid = fork();
	
	if(pid == 0){
		printf("child : hello\n"); 
	}
	
	else {
	wait(NULL);	
	printf("parent : goodbye\n");
	
	}
	//wait 함수를 쓰지 않고 parent부터 실행되게 확신할 수 없음.
	return 0;
}
