/*********************************************************************************
 * Este programa sirve para garantizar que al ejecutar la función fork, el       *
 * proceso padre espere la impresión del hijo antes de realizar la suya sin usar *
 * la función wait                                                               *
 *********************************************************************************/

#include <stdio.h>                                                                 
#include <stdlib.h>                                                                
#include <unistd.h>                                                                
#include <string.h>                                                              
#include <sys/wait.h>

int main(int argc, char ** argv){
	pid_t pid;
  	pid = fork();
	
	if(pid!=0){
		waitpid(pid,NULL,0);
		printf("Goodbye");
	}else{
		printf("Hello");
		sleep(2);
	}
	
	return 0;
	
}
