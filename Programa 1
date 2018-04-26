/********************************************************************************
 * Este programa sirve para mostrar que la variable X creada durante un proceso * 
 * es independiente para el proceso padre y para el proceso hijo después de     *
 * ejecutar la función fork y cambiar su valor                                  * 
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(char * argc, char ** argv){

        int x;        
        pid_t pid = fork();
        
        if(!pid){
          x=2;
          printf("Soy el hijo, mi pid es %d y mi X es %d\n", getpid(), x);
        }else{
          wait(NULL);
		      x=3;
          printf("Soy el padre, mi pid es %d y mi X es %d\n", getpid(), x);
	      }
        
        return 0;

}
