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
	

	// TODO
	// Add code to spawn processes for the first 9 commands
	// And add code to execute cd, exit, help commands
	// Use the example provided in myspawn.c
	if (!isAllowed(argv[0])){
		printf("NOT ALLOWED!\n");
		continue;
	} 
	
	}	
	
    return 0;

}