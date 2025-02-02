#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
   printf("Poczatek\n");
   if (fork() == 0){
      execlp("ls", "ls", "-a", NULL);
      perror("Blad uruchmienia programu");
      exit(1);
   }
   wait(NULL);
   printf("Koniec\n");
}
