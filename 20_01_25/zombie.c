#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
void funkcja(int nr){
	printf("potomek zakonczony, nr zakonczenia: %d\n",nr);
}
int main(){
	//signal(SIGCLD, SIG_IGN);
	signal(SIGCLD, funkcja);
	if(fork()==0){
		exit(1);
	}
	sleep(30);
	wait(NULL);
}
