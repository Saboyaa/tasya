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
    std::ifstream process;
    std::string pid_path= "/proc/";
    pid_path += dp->d_name;
    pid_path += "/cmdline";
    process.open(pid_path);
    if(!process.is_open()){
      perror("Pid cannot be open");
    }
    std::string line;
    while(getline(process,line)){
      if(line!=""){
        std::cout<<dp->d_name<<"\n";
        std::cout<<"--> "<<line<<"\n";
      }else{continue;}
    }
  }  
  closedir(dir);
  return 0;
}
