#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   printf("Poczatek\n");
   execlp("ls", "ls", "-a", NULL);
   printf("Koniec\n");
}
