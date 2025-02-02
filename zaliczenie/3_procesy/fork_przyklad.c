#include <stdio.h>
#include <unistd.h>

int main(){
	printf("start\n");
	fork();
	printf("koniec\n");
}
