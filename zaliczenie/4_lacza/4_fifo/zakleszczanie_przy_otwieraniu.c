#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/wait.h>


#define MAX 512

int main(int argc, char* argv[]) {
   int pdesk;

   if (mkfifo("/tmp/fifo", 0600) == -1){
      perror("Tworzenie kolejki FIFO");
      exit(1);
   }

   if (fork() == 0){ // proces potomny
      close(1);
      open("/tmp/fifo", O_WRONLY);
      execvp("ls", argv);
      perror("Uruchomienie programu ls");
      exit(1);
   }
   else { // proces macierzysty
      char buf[MAX];
      int lb, i;

      wait(NULL);
      pdesk = open("/tmp/fifo", O_RDONLY);
      while ((lb=read(pdesk, buf, MAX)) > 0){
         for(i=0; i<lb; i++)
            buf[i] = toupper(buf[i]);
         write(1, buf, lb);
      }
   }
}
