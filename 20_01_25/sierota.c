#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	if(fork()==0){
		printf("ppid: %d\n", getppid());
		
		sleep(3);
		printf("ppid: %d\n", getppid());
	}
	sleep(1);
	exit(0);
}
