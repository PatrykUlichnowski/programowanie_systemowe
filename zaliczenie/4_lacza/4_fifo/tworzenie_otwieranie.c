#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
   int pdesk;

   if (mkfifo("/tmp/fifo", 0600) == -1){
      perror("Tworzenie kolejki FIFO");
      exit(1);
   }

   switch(fork()){
      case -1: // blad w tworzeniu procesu
         perror("Tworzenie procesu");
         exit(1);
      case 0:
         pdesk = open("/tmp/fifo", O_WRONLY);
         if (pdesk == -1){
            perror("Otwarcie potoku do zapisu");
            exit(1);
         }
         if (write(pdesk, "Hallo!", 7) == -1){
            perror("Zapis do potoku");
            exit(1);
         }
         exit(0);
      default: {
         char buf[10];

         pdesk = open("/tmp/fifo", O_RDONLY);
         if (pdesk == -1){
            perror("Otwarcie potoku do odczytu");
            exit(1);
         }
         if (read(pdesk, buf, 10) == -1){
            perror("Odczyt z potoku");
            exit(1);
         }
         printf("Odczytano z potoku: %s\n", buf);
      }
   }
}
