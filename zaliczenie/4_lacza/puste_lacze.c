#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   int pdesk[2];

   pipe(pdesk);

   if (fork() == 0){ // proces potomny
      write(pdesk[1], "Hallo!", 7); 
      exit(0);
   }
   else { // proces macierzysty
      char buf[10];
      read(pdesk[0], buf, 10);
      read(pdesk[0], buf, 10);
      printf("Odczytano z potoku: %s\n", buf);
   }
}
