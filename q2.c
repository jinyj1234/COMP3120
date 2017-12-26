#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(){
	int fd;
	fd = open("q2.txt",O_WRONLY);
	int pid = fork();
	if(pid==0){
	write(fd,"this is child process",24); //자식 프로세스에서 접근
	}

	else {
		write(fd,"this is parent process",24); //부모 프로세스에서 접근
	}
	// 양쪽다 접근 가능, 하지만 결과값이 이상하게 나옴
return 0;
}
