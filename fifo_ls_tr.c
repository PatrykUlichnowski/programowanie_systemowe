#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
int main(int argc, char* argv[]) {

   if(mkfifo("kol_fifo", 0600) == -1){
   	perror("blad tworzenia kolejki");
   }

   switch(fork()){
      case -1: // blad w tworzeniu procesu
         perror("Tworzenie procesu");
         exit(1);
      case 0: // proces potomny
	 //pdesk[1] = open("kol_fifo", O_WRONLY);
	 dup2(open("kol_fifo", O_WRONLY), 1);
   	 unlink("kol_fifo");
         execvp("ls", argv);
         perror("Uruchomienie programu ls");
         exit(1);
      default: { // proces macierzysty
	 //`:pdesk[0] = open("kol_fifo", O_RDONLY);
         dup2(open("kol_fifo", O_RDONLY), 0);
   	 unlink("kol_fifo");
         execlp("tr", "tr", "a-z", "A-Z", NULL);
         perror("Uruchomienie programu tr");
         exit(1);
      }
   }
}
