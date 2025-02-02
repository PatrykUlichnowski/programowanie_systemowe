#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
   if (fork() == 0){
      sleep(30);
      exit(0);
   }
   exit(0);
}
