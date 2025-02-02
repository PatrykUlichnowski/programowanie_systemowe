#include <fcntl.h>
#include <sys/stat.h>

int main(){
   mkfifo("kolFIFO", 0600);
   open("kolFIFO", O_RDONLY);
}
