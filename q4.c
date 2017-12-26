#include <stdio.h>
#include <unistd.h>
int main(){
	int pid = fork(); //포크하고,
	execl("/bin/ls","ls",NULL); //exec 를 호출해 bin/ls를 실행
	
	return 0;

}
