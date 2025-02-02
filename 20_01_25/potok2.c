#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   int pdesk[2];

   if (pipe(pdesk) == -1){
      perror("Tworzenie potoku");
      exit(1);
   }

   switch(fork()){
      case -1:    // blad w tworzeniu procesu
         perror("Tworzenie procesu");
         exit(1);
      case 0:     // proces potomny
	 dup2(pdesk[1], 1);
	 execlp("ls", "ls", "-l", NULL);// to zastepuje reszte ponizej
         if (write(pdesk[1], "Hello!", 7) == -1){
            perror("Zapis do potoku");
            exit(1);
         }
	 sleep(1);
         if (write(pdesk[1], "Hallo!", 7) == -1){
            perror("Zapis do potoku");
            exit(1);
         }
	 //execlp("ls", "ls", "-l", NULL);
         exit(0);
      default: {  // proces macierzysty
         char buf[20];
	 int n;
	 close(pdesk[1]);
         while ((n=read(pdesk[0], buf, 18)) > 0){
	 	buf[n] = '\0';
	 	if (n  == -1){
            		perror("Odczyt z potoku");
            		exit(1);
         	}
         	printf("Odczytano z potoku: %s\n", buf);
	}
      }
   }
}
