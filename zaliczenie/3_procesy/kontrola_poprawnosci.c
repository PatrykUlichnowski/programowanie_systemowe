#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
   printf("Poczatek\n");
   switch (fork()){
      case -1: 
         perror("Blad utworzenia procesu potomnego");
         break;
      case 0: /* proces potomny */
         execlp("ls", "ls", "-a", NULL);
         perror("Blad uruchmienia programu");
         exit(1);
      default: /* proces macierzysty */
         if (wait(NULL) == -1)
            perror("Blad w oczekiwaniu na zakonczenie potomka");
   }
   printf("Koniec\n");
}
