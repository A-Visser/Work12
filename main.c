#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc, char * argv[]){
  unsigned long total_memory = 0;
  char str[25];
  DIR * d;
  struct dirent *entry;
  if(argv[1] != NULL) {
    printf("Showing directory %s \n", argv[1]);
    d = opendir(argv[1]);
    if (d <= 0) {
      printf("\nError: %s", strerror(errno));
      return 0;
    }
  } else {
    printf("Enter a path: ");
    fgets(str, sizeof(str)-1, stdin);
    int i = 0;
    while (str[i]) {
      i++;
    }
    str[i-1] = 0;
    d = opendir(argv[0]);
    if (d <= 0) {
      printf("\nError: %s", strerror(errno));
      return 0;
    }
  }
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
  printf("Directory Size: %lu", total_memory);
  return 0;
}
