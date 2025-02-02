#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#define MAX 512

int main(int argc, char* argv[]) {
   int pdesk[2];

   if (pipe(pdesk) == -1){
      perror("Tworzenie potoku");
      exit(1);
   }

   if (fork() == 0){ // proces potomny
      dup2(pdesk[1], 1);
      execvp("ls", argv);
      perror("Uruchomienie programu ls");
      exit(1);
   }
   else { // proces macierzysty
      char buf[MAX];
      int lb, i;

      close(pdesk[1]);
      wait(0);
      while ((lb=read(pdesk[0], buf, MAX)) > 0){
         for(i=0; i<lb; i++)
            buf[i] = toupper(buf[i]);
         write(1, buf, lb);
      }
   }
}
