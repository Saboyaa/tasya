#include <iostream>
#include <fstream>
#include <errno.h>
#include <dirent.h>
int main (int argc, char *argv[]) {
  DIR *dir;
  struct dirent *dp;

  if((dir = opendir("/proc")) == NULL){
    perror("Cannot open .");
    exit (1);
  } //Error
  while((dp = readdir(dir)) != NULL){
    std::cout<<dp->d_name<<"\n";
  }  
  closedir(dir);
  return 0;
}
