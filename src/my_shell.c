#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define CAP 1024

/*
 * Brady Lange
 * Program 4
 * 5/4/18
 * client.c
 * This program emulates the shell in bash and executes commands by forking them and waiting until they're finished to continue.
 */

//Main function
int main()
{

	//Variables
	char *path = "/bin/";   
	char compPath[20]; 
	char *input[50];  
	char cmd[CAP];

	while(1)
	{
		printf("myshell$ ");
		//While loop flag
		if(!fgets(cmd, CAP, stdin))
		{
			//Exit the while loop
			break;
		}

		char *token;
		token = strtok(cmd, " ");
		int i = 0;

		while(token != NULL && i < 100)
		{
			input[i] = token;
			token = strtok(NULL, " ");
			i++;
		}

		input[i] = NULL;

		strcpy(compPath, path);
		strcat(compPath, input[0]);

		for(i = 0; i < strlen(compPath); i++)
		{
			if(compPath[i] == '\n')
			{
				compPath[i] = '\0';
			}
		}

		//Fork process to execute command
		int childPID = fork();
		if(childPID == 0)
		{
			execvp(compPath, input);
			fprintf(stderr, "Child could not be processed.\n");
		}
		//Wait for the fork to be done
		else
		{
			wait(NULL);
			printf("\n");
		}

	}

	return 0;
	
} //End main function
