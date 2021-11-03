#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
  unsigned long total_memory = 0;
  DIR * d;
  struct dirent *entry;
  d = opendir("./");
  entry = readdir(d);
  while(entry){
    struct stat s;
    stat(entry->d_name, &s);
    total_memory += s.st_size;
    if(S_ISDIR(s.st_mode)){
      printf("Directory: ");
    }
    printf("%s\n", entry ->d_name);
    entry = readdir(d);
  }
  printf("Memory use: %lu", total_memory);
  return 0;
}
