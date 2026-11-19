#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define N 12

extern char **environ;

char *allowed[N] = {"cp","touch","mkdir","ls","pwd","cat","grep","chmod","diff","cd","exit","help"};

int isAllowed(const char*cmd) {
	// TODO
	// return 1 if cmd is one of the allowed commands
	// return 0 otherwise
	int len = 12;
	for (int i = 0; i<len; i++){
		if (strcmp(allowed[i],cmd) == 0) return 1;
	}
	
	return 0;
}
void help() {
    printf("The allowed commands are:\n");
    printf("cp\n");
    printf("touch\n");
    printf("mkdir\n");
    printf("ls\n");
    printf("pwd\n");
    printf("cat\n");
    printf("grep\n");
    printf("chmod\n");
    printf("diff\n");
    printf("cd\n");
    printf("exit\n");
    printf("help\n");
}

int main() {

    // TODO
    // Add variables as needed
	posix_spawnattr_t attr;
	posix_spawnattr_init(&attr);
	int status;
	pid_t pid;

    char line[256];

    while (1) {

	fprintf(stderr,"rsh>");
	
	

	if (fgets(line,256,stdin)==NULL) continue;

	if (strcmp(line,"\n")==0) continue;

	line[strlen(line)-1]='\0';
	char *argv[21];
	char* tok;
	int position = 0;
	
	tok = strtok(line, " ");
	
	while (tok != NULL){
		argv[position] = tok;
		position ++;
		tok = strtok(NULL, " ");
	}
	argv[position] = NULL;
	int argc = position;
	

	// TODO
	// Add code to spawn processes for the first 9 commands
	// And add code to execute cd, exit, help commands
	// Use the example provided in myspawn.c

	if (strcmp(argv[0], "exit") == 0) {
    	return 0;
	} else if (strcmp(argv[0], "help") == 0) {
    	help();
	} else if (strcmp(argv[0], "cd") == 0){
		if (argc != 2){
			printf("rsh: cd: too many arguments\n");
		} else {
			chdir(argv[1]);
		}
		continue;
	}




	

    // Set flags if needed, for example, to specify the scheduling policy
    // posix_spawnattr_setflags(&attr, POSIX_SPAWN_SETSCHEDULER);

    // Spawn a new process
    posix_spawnp(&pid, argv[0], NULL, NULL, argv, environ);

	waitpid(pid, &status, 0);

	}	
	
    return 0;

}