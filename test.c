#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

	int i=20;
	char s[50];
	char pid[15];
	printf("What pid number do you want? : ");
	scanf("%s",pid); // pid를 입력받는 부분
	
	char pid1[50] = "/proc/"; char pid2[50] = "/proc/"; //경로 지정
	int utime=0,stime=0,ans=0;

	strcat(pid1,pid); strcat(pid1,"/stat"); //경로 지정
	strcat(pid2,pid); strcat(pid2,"/status"); //경로 지정

	while(1){ // 반복적으로 주기마다 나타내기 위한 루프

	FILE * fpp = fopen(pid1,"r"); //cpu 사용량을 확인하기 위함
	for(i=1;i<19;i++){
		fscanf(fpp,"%s",s);
		if(i==14){	utime = atoi(s);	} // 14번째 utime 확인
		if(i==15){	stime = atoi(s);	} // 15번째 stime 확인

	}
		ans = utime + stime;



	FILE * fp = fopen(pid2,"r"); //memory 사용량을 확인하기 위함

	int j=50;
	for(j=0;j<50;j++){
		fscanf(fp,"%s",s);
	if(!strcmp(s,"VmSize:")){break;}
	}
	fscanf(fp,"%s",s);
	printf("size of memory usage is %s kB \n",s);

	fclose(fpp);
	fclose(fp);
	printf("the time of cpu usage is %d milisecond(u : %d, s : %d )\n",100*ans,utime,stime);

	sleep(2); //주기적으로 나타내기 위한 대기시간
}


	return 0;
}
