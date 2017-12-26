#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(){
	int a;
	int pid = fork();
	
	if(pid ==0){
		printf("this is child \n");
	} //자식 wait() 에서 리턴된 값은 -1 이다, 
	// 자식 프로세스에 wait() 를 쓰면 결과값에는 의미가 없다.
	else {
		a = wait(NULL);
		printf("this is parent and return value of wait() is %d %d\n",a,pid);
	}
	// 부모 프로세스에 wait()를 쓰면 리턴값은 부모의 pid값과 같고,
	// 자식 프로세스가 먼저 실행한다.
	return 0;
}
