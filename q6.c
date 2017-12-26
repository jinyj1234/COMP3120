#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 512
#define TOTALFORK 2;

int main()
{
	const char *msg[] = {"child1","child2"};
	char buffer[BUFFER_SIZE];
	int filedes[2],nRead,i;
	int ppid;
	pid_t pid;

	if(pipe(filedes)==-1){ //파이프가 -1이면 제끼고 
		printf("fail to call pipe()\n");
		exit(1);
	}

	if((pid = fork())==-1){
	printf("fail to call fork()\n");
	exit(1);
	}
			// pipe를 실행했을때 
	if(pid>0){
	ppid = fork(); // 2번째 자식프로세스 생성
	close(filedes[0]);
	if(ppid==0){ // 2번째 자식프로세스에서 write 하고  
		for(i=0;i<2;i++){
		strcpy(buffer,msg[i]);
		write(filedes[1],buffer,BUFFER_SIZE);
	}
	}
	
	
	}

	else if(pid==0){ //1번째 자식 프로세스에서 read 함  
	close(filedes[1]);

	for(i=0;i<2;i++){
		nRead = read(filedes[0],buffer,BUFFER_SIZE);
		printf("[child] %s\n",buffer);
	}
	}

	return 0;


}
