#include <stdio.h>
#include <fcntl.h>
int main(int argc, char *argv[]){
	printf("test\n");
	printf("ilosc argumentow: %d\n", argc);
	for (int i = 1; i <= argc; i++)
		printf("argument: %s\n", argv[i]);
	return 0;
}
