#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main (void){
	pid_t parent;
	pid_t child;

	int pid = getpid();
	printf("pid: %d", pid);

	if (fork() == 0){
		printf("In child");
	}
	else {
		printf("In parent");
	}
	
	sleep(10);
}
