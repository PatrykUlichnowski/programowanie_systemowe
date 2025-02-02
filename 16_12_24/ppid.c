#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){
	printf("  poczatek\n");
	int p0 = fork();
	int p1 = getpid();
	int p2 = getppid();
	printf("fork %d\n",p0);
	printf("pid %d\n",p1);
	printf("ppid %d\n",p2);
	printf("  koniec\n");
	pid_t p3 = wait(NULL);
	printf("END %d\n",p3);
}
