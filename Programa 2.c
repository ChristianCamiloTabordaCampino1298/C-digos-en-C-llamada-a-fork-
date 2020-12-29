/*********************************************************************************
 * Este programa sirve para mostrar que al ejecutar la función fork, tanto el    *
 * padre como el hijo comparten el mismo descriptor para entrar a escribir sobre * 
 * un archivo de texto                                                           *
 *********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(char * argc, char ** argv){
  
  int x;
  pid_t pid;
  char *filename="code-02.txt";
  int fd;
  
  fd = open(filename, O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);  
  
  x = 100;
  pid = fork();
  
  if (pid == 0){
    x++;
    dprintf(fd, "Soy el hijo, mi PID es %d y mi X es %d\n", getpid(), x);    
  }else{
    x+=2;
	  dprintf(fd, "Soy el padre, mi PID es %d y mi X es %d\n", pid, x);   
  }
  
  close(fd);
  
}
