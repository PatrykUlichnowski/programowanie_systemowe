#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
   int pid1, pid2, status;

   pid1 = fork();
   if (pid1 == 0) /* proces potomny */
      exit(7);
   /* proces macierzysty */
   printf("Mam potomka o identyfikatorze %d\n", pid1);
   pid2 = wait(&status);
   printf("Status zakonczenia procesu %d: %x\n", pid2, status);
}
