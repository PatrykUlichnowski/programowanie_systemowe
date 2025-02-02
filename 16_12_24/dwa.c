#include <unistd.h>
#include <stdio.h>
int main(){
	printf("start\n");
	execlp("ls", "ls", "-l", NULL);
	perror("blad exec\n");
}
