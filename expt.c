#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
pid_t parent;
pid_t child_parent;
pid_t child_child;
void ChildProcess(void);

int main(void){
	pid_t parent;
	pid_t child_parent;
	pid_t child_child;

	parent = fork();
	if (parent == 0){
	printf("In child");
	ChildProcess();
	}
	else {
	printf("in parent");
	sleep(10);
	}
}

void ChildProcess(void){
	
	child_parent = getpid();

	if (child_parent == 0){
		child_child = fork();
		if (child_child == 0){
			printf("I am child's child");
			printf("child_child: %d", child_child);
		}
		else {
			sleep(10);
		}
	}

}
