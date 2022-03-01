#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int num;
int collatz(int num);

int main()
{
	printf("Please enter you number greater than 1\n");
	scanf("%d", &num);
	pid_t pid = fork();

	if (pid < 0){
		printf("Error");
		return -1;
		}	
	else if (pid == 0){
		printf("%d", num);
		while(num != 1)
				{
			num = collatz(num);
			printf("%d \n", num);	
			}
		}
	else {
		wait(NULL);
		printf("Child complete");
		}

}

int collatz(int num){
	
	if (num%2 == 0) {
		num = num/2;
	}
	else {
		num = (3*num)+1;
	}
	
	return num;

}
